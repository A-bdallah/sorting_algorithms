#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merge two subarrays of array[]
 * @array: Pointer to the array to be sorted
 * @left: Index of the left subarray
 * @mid: Index of the middle element
 * @right: Index of the right subarray
 * @temp: Temporary array for merging
 */
void merge(int *array, int left, int mid, int right, int *temp)
{
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];

    while (j <= right)
        temp[k++] = array[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        array[i] = temp[k];
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

