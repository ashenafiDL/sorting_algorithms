#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	if (size < 2)
		return;

	low = 0;
	high = size - 1;
	sort(array, size, low, high);
}

/**
 * sort - sorts a sub array
 *
 * @arr: the sub array to sorted
 * @low: first index of sub array
 * @high: last index of sub array
 */
void sort(int *arr, size_t size, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, size, low, high);
		sort(arr, size, low, pivot_index - 1);
		sort(arr, size, pivot_index + 1, high);
	}
}

int partition(int *arr, size_t size, int low, int high)
{
	int pivot = arr[high],
	    i = low - 1;

	while (low < high)
	{
		if (arr[low] < pivot)
		{
			i++;
			swap_array(arr, i, low);
			print_array(arr, size);
		}
		low++;
	}

	swap_array(arr, i + 1, high);
	print_array(arr, size);
	return (i + 1);
}

void swap_array(int *array, int a, int b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}