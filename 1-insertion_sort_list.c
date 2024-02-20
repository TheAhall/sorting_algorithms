#include "sort.h"

/**
 * node_swap - swaps a node of a list
 * @node: the node
 * @list: the list
 * Return: the final list
 */
listint_t *node_swap(listint_t *node, listint_t **list)
{
	listint_t *prev = node->prev, *curr = node;

	prev->next = curr->next;
	if (curr->next != NULL)
		curr->next->prev = prev;
	curr->next = prev;
	curr->prev = prev->prev;
	prev->prev = curr;
	if (curr->prev != NULL)
		curr->prev->next = curr;
	else
		*list = curr;
	return (curr);
}

/**
 * insertion_sort_list - the Insertion sort algorithm
 * @list: the list should be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	while (node != NULL)
	{
		while(node->prev != NULL && node->prev->n > node->n)
		{
			node = node_swap(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
