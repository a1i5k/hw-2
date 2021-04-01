#include "gtest/gtest.h"
#include "stdlib.h"

extern "C" {
    #include "single_thread.c"
    #include "multi_thread.c"
}

TEST(test1, single) {
    int size = 8;
    int *array = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        array[i] = i;
    }
    int result = single_thread(array, size);
    EXPECT_EQ(result, size);
    free(array);
}

TEST(test2, single) {
    size_t size = 8;
    int j = size;
    int *array = (int *) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        array[i] = j--;
    }
    int result = single_thread(array, size);
    EXPECT_EQ(result, 1);
    free(array);
}

TEST(test3, single) {
    size_t size = 3;
    int j = size;
    int *array = (int *) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        array[i] = j--;
    }
    int result = single_thread(array, size);
    EXPECT_EQ(result, 1);
    free(array);
}

TEST(test4, single) {
    int size = 3;
    int *array = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        array[i] = i;
    }
    int result = single_thread(array, size);
    EXPECT_EQ(result, size);
    free(array);
}

TEST(test5, single) {
    int result = single_thread(NULL, 1);
    EXPECT_EQ(result, -1);
}

TEST(test6, single) {
    size_t size = 3;
    int *array = (int *) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        array[i] = i;
    }
    int result = single_thread(array, 0);
    EXPECT_EQ(result, -2);
    free(array);
}

TEST(test7, single) {
    int size = 1;
    int *array = (int *) malloc(sizeof(int));
    array[0] = 1;
    int result = single_thread(array, size);
    EXPECT_EQ(result, size);
    free(array);
}

TEST(test8, single) {
    size_t size = 8;
    int *array = (int *) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        array[i] = i;
    }
    array[5] = 1;
    int result = single_thread(array, size);
    EXPECT_EQ(result, 5);
    free(array);
}

TEST(test9, single) {
    size_t size = 8;
    int *array = (int *) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        array[i] = i;
    }
    array[5] = 1;
    array[3] = 1;
    int result = single_thread(array, size);
    EXPECT_EQ(result, 3);
    free(array);
}

TEST(test10, single) {
    size_t size = 104857600;
    int *array = (int *) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        array[i] = i;
    }
    array[5] = 1;
    array[3] = 1;
    int result = single_thread(array, size);
    EXPECT_EQ(result, 104857595);
    free(array);
}

TEST(test11, single_vs_multi) {
    size_t size = 104857600;
    int *array = (int *) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        array[i] = i;
    }
    array[5] = 1;
    array[3] = 1;
    int result = single_thread(array, size);
    EXPECT_EQ(result, multi_thread(array, size));
    free(array);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

