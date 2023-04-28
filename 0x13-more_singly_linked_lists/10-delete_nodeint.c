0x13. C - More singly linked lists

0x13. C - More singly linked lists

lists.h


#ifndef LISTS_H

#define LISTS_H


#include <stdio.h>

#include <stdlib.h>


/**
 *
 *  * struct listint_s - singly linked list
 *
 *   * @n: integer
 *
 *    * @next: points to the next node
 *
 *     *
 *
 *      * Description: singly linked list node structure
 *
 *       * for alx project
 *
 *        */

typedef struct listint_s

{

	        int n;

		        struct listint_s *next;

} listint_t;


size_t print_listint(const listint_t *h);

size_t listint_len(const listint_t *h);

listint_t *add_nodeint(listint_t **head, const int n);

listint_t *add_nodeint_end(listint_t **head, const int n);

void free_listint(listint_t *head);

void free_listint2(listint_t **head);

int pop_listint(listint_t **head);

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);

int sum_listint(listint_t *head);

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);

int delete_nodeint_at_index(listint_t **head, unsigned int index);

listint_t *reverse_listint(listint_t **head);

size_t print_listint_safe(const listint_t *head);

size_t free_listint_safe(listint_t **h);

listint_t *find_listint_loop(listint_t *head);


#endif

0-print_listint.c


#include "lists.h"


/**
 *
 *  * print_listint - prints all the elements of a linked list
 *
 *   * @h: linked list of type listint_t to print
 *
 *    *
 *
 *     * Return: number of nodes
 *
 *      */

size_t print_listint(const listint_t *h)

{

	        size_t num = 0;


		        while (h)

				        {

						                printf("%d\n", h->n);

								                num++;

										                h = h->next;

												        }


			        return (num);

}


















1-listint_len.c


#include "lists.h"


/**
 *
 *  * listint_len - returns the number of elements in a linked lists
 *
 *   * @h: linked list of type listint_t to traverse
 *
 *    *
 *
 *     * Return: number of nodes
 *
 *      */

size_t listint_len(const listint_t *h)

{

	        size_t num = 0;


		        while (h)

				        {

						                num++;

								                h = h->next;

										        }


			        return (num);

}



















2-add_nodeint.c


#include "lists.h"


/**
 *
 *  * add_nodeint - adds a new node at the beginning of a linked list
 *
 *   * @head: pointer to the first node in the list
 *
 *    * @n: data to insert in that new node
 *
 *     *
 *
 *      * Return: pointer to the new node, or NULL if it fails
 *
 *       */

listint_t *add_nodeint(listint_t **head, const int n)

{

	        listint_t *new;


		        new = malloc(sizeof(listint_t));

			        if (!new)

					                return (NULL);


				        new->n = n;

					        new->next = *head;

						        *head = new;


							        return (new);

}
















3-add_nodeint_end.c


#include "lists.h"


/**
 *
 *  * add_nodeint_end - adds a node at the end of a linked list
 *
 *   * @head: pointer to the first element in the list
 *
 *    * @n: data to insert in the new element
 *
 *     *
 *
 *      * Return: pointer to the new node, or NULL if it fails
 *
 *       */

listint_t *add_nodeint_end(listint_t **head, const int n)

{

	        listint_t *new;

		        listint_t *temp = *head;


			        new = malloc(sizeof(listint_t));

				        if (!new)

						                return (NULL);


					        new->n = n;

						        new->next = NULL;


							        if (*head == NULL)

									        {

											                *head = new;

													                return (new);

															        }


								        while (temp->next)

										                temp = temp->next;


									        temp->next = new;


										        return (new);

}





4-free_listint.c


#include "lists.h"


/**
 *
 *  * free_listint - frees a linked list
 *
 *   * @head: listint_t list to be freed
 *
 *    */

void free_listint(listint_t *head)

{

	        listint_t *temp;


		        while (head)

				        {

						                temp = head->next;

								                free(head);

										                head = temp;

												        }

}






















5-free_listint2.c


#include "lists.h"


/**
 *
 *  * free_listint2 - frees a linked list
 *
 *   * @head: pointer to the listint_t list to be freed
 *
 *    */

void free_listint2(listint_t **head)

{

	        listint_t *temp;


		        if (head == NULL)

				                return;


			        while (*head)

					        {

							                temp = (*head)->next;

									                free(*head);

											                *head = temp;

													        }


				        *head = NULL;

}

















6-pop_listint.c


#include "lists.h"


/**
 *
 *  * pop_listint - deletes the head node of a linked list
 *
 *   * @head: pointer to the first element in the linked list
 *
 *    *
 *
 *     * Return: the data inside the elements that was deleted,
 *
 *      * or 0 if the list is empty
 *
 *       */

int pop_listint(listint_t **head)

{

	        listint_t *temp;

		        int num;


			        if (!head || !*head)

					                return (0);


				        num = (*head)->n;

					        temp = (*head)->next;

						        free(*head);

							        *head = temp;


								        return (num);

}















7-get_nodeint.c


#include "lists.h"


/**
 *
 *  * get_nodeint_at_index - returns the node at a certain index in a linked list
 *
 *   * @head: first node in the linked list
 *
 *    * @index: index of the node to return
 *
 *     *
 *
 *      * Return: pointer to the node we're looking for, or NULL
 *
 *       */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)

{

	        unsigned int i = 0;

		        listint_t *temp = head;


			        while (temp && i < index)

					        {

							                temp = temp->next;

									                i++;

											        }


				        return (temp ? temp : NULL);

}
















8-sum_listint.c


#include "lists.h"


/**
 *
 *  * sum_listint - calculates the sum of all the data in a listint_t list
 *
 *   * @head: first node in the linked list
 *
 *    *
 *
 *     * Return: resulting sum
 *
 *      */

int sum_listint(listint_t *head)

{

	        int sum = 0;

		        listint_t *temp = head;


			        while (temp)

					        {

							                sum += temp->n;

									                temp = temp->next;

											        }


				        return (sum);

}


















9-insert_nodeint.c


#include "lists.h"


/**
 *
 *  * insert_nodeint_at_index - inserts a new node in a linked list,
 *
 *   * at a given position
 *
 *    * @head: pointer to the first node in the list
 *
 *     * @idx: index where the new node is added
 *
 *      * @n: data to insert in the new node
 *
 *       *
 *
 *        * Return: pointer to the new node, or NULL
 *
 *         */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)

{

	        unsigned int i;

		        listint_t *new;

			        listint_t *temp = *head;


				        new = malloc(sizeof(listint_t));

					        if (!new || !head)

							                return (NULL);


						        new->n = n;

							        new->next = NULL;


								        if (idx == 0)

										        {

												                new->next = *head;

														                *head = new;

																                return (new);

																		        }


									        for (i = 0; temp && i < idx; i++)

											        {

													                if (i == idx - 1)

																                {

																			                        new->next = temp->next;

																						                        temp->next = new;

																									                        return (new);

																												                }

															                else

																		                        temp = temp->next;

																	        }


										        return (NULL);

}


































10-delete_nodeint.c


#include "lists.h"


/**
 *
 *  * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 *
 *   * @head: pointer to the first element in the list
 *
 *    * @index: index of the node to delete
 *
 *     *
 *
 *      * Return: 1 (Success), or -1 (Fail)
 *
 *       */

int delete_nodeint_at_index(listint_t **head, unsigned int index)

{

	        listint_t *temp = *head;

		        listint_t *current = NULL;

			        unsigned int i = 0;


				        if (*head == NULL)

						                return (-1);


					        if (index == 0)

							        {

									                *head = (*head)->next;

											                free(temp);

													                return (1);

															        }


						        while (i < index - 1)

								        {

										                if (!temp || !(temp->next))

													                        return (-1);

												                temp = temp->next;

														                i++;

																        }



							        current = temp->next;

								        temp->next = current->next;

									        free(current);


										        return (1);

}
