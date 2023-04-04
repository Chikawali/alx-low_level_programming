#include "lists.h"

/**
 * print_listint - Prints all the elements of a listint_t lists.
 * @h: Pointer to the list.
 * Return: Number of nodes.
 **/
size_t print_listint(const listint_t *h)
{
	const listint_t *node = h;
	size_t arrow = 0;

	while (node)
	{
		printf("%\n", node->n);
		arrow++;
		node = node->next;
	}

	return (arrow);
}
