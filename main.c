#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/include/single_thread.h"
#include "lib/include/multi_thread.h"

#define SIZE 104857600  // 100 * 1024 * 1024 = 100 МБ
#define MEMORY_NO_ALLOCATED -3
#define MICROSECOND_IN_SECOND 1000000
#define NANOSECOND_IN_MICROSECOND 1000

int main() {
    int *array;
    array = (int *)malloc(SIZE * sizeof(int));
    if (array == NULL) {
        printf("No memory allocated");
        return MEMORY_NO_ALLOCATED;
    }
    unsigned int seed = time(NULL);

    for (size_t i = 0; i < SIZE; ++i) {
        array[i] = rand_r(&seed) % 10 + 30;
    }
    array[5] = 1;
    array[3] = 1;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    multi_thread(array, SIZE);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    printf("time multi:  %ld nanoseconds\n", (end.tv_sec - start.tv_sec)
     * MICROSECOND_IN_SECOND + (end.tv_nsec - start.tv_nsec) /
      NANOSECOND_IN_MICROSECOND);
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    single_thread(array, SIZE);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    printf("time single: %ld nanoseconds\n", (end.tv_sec - start.tv_sec)
     * MICROSECOND_IN_SECOND + (end.tv_nsec - start.tv_nsec) /
     NANOSECOND_IN_MICROSECOND);

    free(array);
    return 0;
}
