#include <stdio.h>
#include <stdlib.h>
#include <sort.h>

/**
 * merge - Merge two subarrays of array[]
 * @array: Pointer to the array to be sorted
 * @left: Index of the left subarray
 * @mid: Index of the middle element
 * @right: Index of the right subarray
 * @temp: Temporary array for merging
 */
void merge_sort(int *array, size_t size)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        size_t i, j, k;
        int left[mid];
        int right[size - mid];

        for (i = 0; i < mid; i++)
            left[i] = array[i];
        for (j = 0; i < size; i++, j++)
            right[j] = array[i];

        merge_sort(left, mid);
        merge_sort(right, size - mid);

        i = j = k = 0;
        while (i < mid && j < size - mid)
        {
            if (left[i] <= right[j])
                array[k++] = left[i++];
            else
                array[k++] = right[j++];
        }

        while (i < mid)
            array[k++] = left[i++];
        while (j < size - mid)
            array[k++] = right[j++];
    }
}
/**
 * merge_sort_recursive - Recursive function for merge sort
 * @array: Pointer to the array to be sorted
 * @left: Index of the leftmost element
 * @right: Index of the rightmost element
 * @temp: Temporary array for merging
 */
void merge_sort_recursive(int *array, int left, int right, int *temp)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort_recursive(array, left, mid, temp);
        merge_sort_recursive(array, mid + 1, right, temp);
        printf("Merging...\n[left]: ");
        for (int i = left; i <= mid; i++)
            printf("%d%s", array[i], (i < mid) ? ", " : "\n");
        printf("[right]: ");
        for (int i = mid + 1; i <= right; i++)
            printf("%d%s", array[i], (i < right) ? ", " : "\n");
        merge(array, left, mid, right, temp);
        printf("[Done]: ");
        for (int i = left; i <= right; i++)
            printf("%d%s", array[i], (i < right) ? ", " : "\n");
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int *temp = malloc(sizeof(int) * size);
    if (temp == NULL)
        return;

    merge_sort_recursive(array, 0, size - 1, temp);
    free(temp);
}

