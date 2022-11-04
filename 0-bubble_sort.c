#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using bubble sort
 *
 * @array: the array to be sorted
 * @size: size of the @array
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, temp = 0, swap;

	if (size < 2)
		return;

	i = size - 1;
	while (i >= 0)
	{
		if (swap == 0)
			return;

		swap = 0;
		for (j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);

				swap = 1;
			}
		}
		i--;
	}
}
