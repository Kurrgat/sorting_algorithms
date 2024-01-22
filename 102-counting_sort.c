#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int max = array[0];
	int *counting_array = malloc((max + 1) * sizeof(int));

	if (array == NULL || size < 2)
		return;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	if (counting_array == NULL)
		return;

	for (i = 0; i <= max; i++)
		counting_array[i] = 0;

	/* Populate counting array with frequencies */
	for (i = 0; i < size; i++)
		counting_array[array[i]]++;

	/* Update the original array using counting array */
	j = 0;

	for (i = 0; i <= max; i++)
	{
		while (counting_array[i] > 0)
		{
			array[j] = i;
			counting_array[i]--;
			j++;
		}
	}

	/* Print the counting array */
	print_array(counting_array, max + 1);

	/* Free dynamically allocated memory */
	free(counting_array);
}
