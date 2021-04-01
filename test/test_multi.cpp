#include "gtest/gtest.h"
#include "stdlib.h"

extern "C" {
#include "multi_thread.c"
}

TEST(test1, multi) {
    int size = 8;
    int *array = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        array[i] = i;
    }
    int result = multi_thread(array, size);
    EXPECT_EQ(result, size);
    free(array);
}

TEST(test2, multi) {
    size_t size = 8;
    int j = size;
    int *array = (int *) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        array[i] = j--;
    }
    int result = multi_thread(array, size);
    EXPECT_EQ(result, 1);
    free(array);
}

TEST(test3, multi) {
    size_t size = 3;
    int j = size;
    int *array = (int *) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        array[i] = j--;
    }
    int result = multi_thread(array, size);
    EXPECT_EQ(result, 1);
    free(array);
}

TEST(test4, multi) {
    int size = 3;
    int *array = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        array[i] = i;
    }
    int result = multi_thread(array, size);
    EXPECT_EQ(result, size);
    free(array);
}

TEST(test5, multi) {
    int result = multi_thread(NULL, 1);
    EXPECT_EQ(result, -1);
}

TEST(test6, multi) {
    size_t size = 3;
    int *array = (int *) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        array[i] = i;
    }
    int result = multi_thread(array, 0);
    EXPECT_EQ(result, -2);
    free(array);
}

TEST(test7, multi) {
    int size = 1;
    int *array = (int *) malloc(sizeof(int));
    array[0] = 1;
    int result = multi_thread(array, size);
    EXPECT_EQ(result, size);
    free(array);
}

TEST(test8, multi) {
    size_t size = 8;
    int *array = (int *) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        array[i] = i;
    }
    array[5] = 1;
    int result = multi_thread(array, size);
    EXPECT_EQ(result, 5);
    free(array);
}

TEST(test9, multi) {
    size_t size = 8;
    int *array = (int *) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        array[i] = i;
    }
    array[5] = 1;
    array[3] = 1;
    int result = multi_thread(array, size);
    EXPECT_EQ(result, 3);
    free(array);
}

TEST(test10, multi) {
    size_t size = 104857600;
    int *array = (int *) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        array[i] = i;
    }
    array[5] = 1;
    array[3] = 1;
    int result = multi_thread(array, size);
    EXPECT_EQ(result, 104857595);
    free(array);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
