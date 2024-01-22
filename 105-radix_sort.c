#include "sort.h"

/**
 * getMax - Gets the maximum value in an array
 * @array: The array to find the maximum value
 * @size: Number of elements in the array
 * Return: The maximum value
 */
int getMax(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * countingSort - Performs counting sort based on the significant digit
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void countingSort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the LSD Radix sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = getMax(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		countingSort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
