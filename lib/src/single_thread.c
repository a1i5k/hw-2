#include <stdio.h>
#define ARRAY_IS_NULL -1
#define NOT_CORRECT_SIZE -2

int single_thread(const int *array, size_t size) {
    if (array == NULL) {
        printf("Array is NULL");
        return ARRAY_IS_NULL;
    }
    if (size < 1) {
        printf("Wrong size");
        return NOT_CORRECT_SIZE;
    }

    int max_len = 0, checked_len = 1;
    for (size_t i = 1; i <= size; ++i) {
        if (i != size && array[i - 1] < array[i]) {
            ++checked_len;
        } else {
            if (checked_len > max_len) {
                max_len = checked_len;
            }
            checked_len = 1;
        }
    }
    return max_len;
}
