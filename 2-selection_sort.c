#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *  using the Selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, small_index;

	if (size < 2)
		return;

	i = 0;
	while (i < size)
	{
		small_index = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[small_index])
			{
				small_index = j;
			}
		}

		if (small_index != i)
		{
			temp = array[small_index];
			array[small_index] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
		i++;
	}
}
