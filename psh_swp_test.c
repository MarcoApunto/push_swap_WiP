/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psh_swp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferre <marferre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:17:29 by marferre          #+#    #+#             */
/*   Updated: 2022/10/14 00:34:32 by marferre         ###   ########.fr       */
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