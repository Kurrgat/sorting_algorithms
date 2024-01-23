#include "sort.h"

/**
 * quick_sort_hoare_recursive - recursive function for Hoare partition scheme
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void quick_sort_hoare_recursive(int *array, int low, int high, size_t size)
{
	int pivot = hoare_partition(array, low, high, size);

	if (low < high)
	{
		printf("Partition: ");
		print_array(array + low, high - low + 1);

		quick_sort_hoare_recursive(array, low, pivot, size);
		quick_sort_hoare_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts an array using the Hoare partition scheme
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_hoare_recursive(array, 0, size - 1, size);
}
