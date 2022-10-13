/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psh_swp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferre <marferre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:17:29 by marferre          #+#    #+#             */
/*   Updated: 2022/10/14 00:58:44 by marferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* LIFO -> Last Int First Out */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	struct element *next;
	char *data;
} element;

element *last = NULL;

void	push(element *content)
{
	content->next = NULL;
	if(last == NULL)
		last = content;
	else
	{
		content->next = last;
		last = content;
	}
}

element	*pop()
{
	if(last == NULL)
		return (NULL);
	element *content_return = last;
	last = content_return->next;
	return (content_return);
}

int	main()
{
	element *one = malloc(sizeof(element));
	element *two = malloc(sizeof(element));
	element *three = malloc(sizeof(element));

	one->data = "Te despiertas";
	two->data = "Ganas la lotería";
	three->data = "Consigues pareja";

	push(one);
	push(two);
	push(three);

	element *i = pop();
	while (i != NULL)
	{
		printf("%s\n", i->data);
		i = pop();
	}

	free(one);
	free(two);
	free(three);
}