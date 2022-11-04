#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *head, *left, *tmp;
	int count = 0;

	if (list == NULL || *list == NULL)
		return;

	tmp = *list;
	while (*list && tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	if (count < 2)
		return;

	head = (*list)->next;
	while (head)
	{
		current = head;
		while (current)
		{
			if (current->prev && current->n < current->prev->n)
			{
				left = current->prev;
				swap(left, current, list);
			}
			else
				break;
		}
		head = head->next;
	}
}

/**
 * swap - swaps to nodes
 *
 * @left: the first node
 * @current: the second node
 * @list: the whole list
 */
void swap(listint_t *left, listint_t *current, listint_t **list)
{
	listint_t *temp1, *temp2;

	temp1 = left->prev;
	temp2 = current->next;

	left->next = temp2;
	left->prev = current;

	current->next = left;
	current->prev = temp1;

	if (temp1 != NULL)
		temp1->next = current;
	if (temp2 != NULL)
		temp2->prev = left;

	if (left == *list)
		*list = current;

	print_list(*list);
}
