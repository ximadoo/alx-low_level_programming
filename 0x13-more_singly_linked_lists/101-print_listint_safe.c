#include "lists.h"

/**
 * _r - reallocates memory for an array of pointers to the nodes
 * @list: the old list
 * @size: size of the new list
 * @new: new node
 * Return: pointer to the new list
 */
const listint_t **_r(const listint_t **l, size_t size, const listint_t *new)
{
	const listint_t **nl;
	size_t a;

	nl = malloc(size * sizeof(listint_t *));
	if (nl == NULL)
	{
		free(l);
		exit(98);
	}
	for (a = 0 ; a < size - 1 ; a++)
		nl[a] = l[a];
	nl[a] = new;
	free(l);
	return (nl);
}
/**
 * print_listint_safe - prints a listint_t linked list
 * @head: head
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node = 0, a;
	const listint_t **l = NULL;

	while (head != NULL)
	{
		for (a = 0 ; a < node ; a++)
		{
			if (head == l[a])
			{
				printf("->[%p] %d\n", (void *)head, head->n);
				free(l);
				return (node);
			}
		}
		node++;
		l = _r(l, node, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(l);
	return (node);
}
