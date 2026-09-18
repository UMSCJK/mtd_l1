#include <stdio.h>

/**
 * @brief Removes duplicates from an array sorted in ascending order
 *
 * Compacts the given array in place: all unique values are moved to the
 * beginning of the array and keep their ascending order. The value pointed
 * to by len is overwritten with the number of remaining (unique) elements.
 *
 * Example:
 *   int arr[] = {1, 1, 2, 2, 2, 3, 4, 4};
 *   unsigned int len = 8;
 *   int removed = removeDuplicates(arr, &len);
 *   // after the call: arr = {1, 2, 3, 4, ...}, len = 4, removed = 4
 *
 * @warning The array must be sorted in ascending order, otherwise the result
 *          is undefined. The elements stored after the first *len entries are
 *          left in an unspecified state, because the array is modified
 *          in place without allocating any additional memory.
 *
 * @param arr Pointer to the first element of the array (must not be NULL)
 * @param len Pointer to the number of elements in the array; it is
 *            overwritten with the new length (must not be NULL)
 * @returns The number of removed elements, or -1 if arr or len is NULL
 */
int removeDuplicates(int* arr, unsigned int* len)
{
    if (arr == NULL || len == NULL) {
        return -1;
    }

    unsigned int oldLen = *len;
    if (oldLen == 0) {
        return 0;
    }

    /* The first element is always unique. writeIndex is the position where
       the next unique value has to be written. */
    unsigned int writeIndex = 1;
    for (unsigned int readIndex = 1; readIndex < oldLen; ++readIndex) {
        if (arr[readIndex] != arr[writeIndex - 1]) {
            arr[writeIndex] = arr[readIndex];
            ++writeIndex;
        }
    }

    *len = writeIndex;
    return (int)(oldLen - writeIndex);
}

int main()
{
    unsigned int a;

    printf("input non-negative number:\n");
    scanf("%u", &a);

    printf("the value of `a` is %u\n", a);

    unsigned int* pa = &a;
    printf("the pointer value is %p\n", (void *)pa);

    int secondNumber;
    printf("input a number:\n");
    scanf("%d", &secondNumber);
    printf("the value of `secondNumber` is %d\n", secondNumber);

    /* Task 4.3: demonstration of removeDuplicates */
    int numbers[] = {1, 1, 2, 2, 2, 3, 4, 4};
    unsigned int count = sizeof(numbers) / sizeof(numbers[0]);

    int removed = removeDuplicates(numbers, &count);

    printf("removeDuplicates: %d duplicate(s) removed, %u element(s) left:",
           removed, count);
    for (unsigned int i = 0; i < count; ++i) {
        printf(" %d", numbers[i]);
    }
    printf("\n");

    return 0;
}
