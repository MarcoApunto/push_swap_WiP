// Make stack and add values (int)
// Will need putnbr (uses putstr and putchar...)????

#include <stdlib.h>
#include <stdio.h>

// stack of int
typedef struct s_stack
{
	char			*nbr;
	struct s_stack	*next;
}	t_stack;

void	ft_push(t_stack *element, t_stack *last)
{
	element->next = NULL;
	if (!last)
		last = element;
	else
	{
		element->next = last;
		last = element;
	}
}

void	*ft_pop(t_stack *last)
{
	t_stack *content;

	if (!last)
		return (NULL);
	content = last;
	last = content;
	return (content);
	
}

int main(int ac, char **av)
{
	size_t	i;
	t_stack	*j;
	t_stack	*last;
	t_stack	*elmt;

	elmt = malloc(sizeof(t_stack));
	if (!elmt)
		return (NULL);
	last = NULL;
	i = 0;
	if (ac > 1)
	{	
		while(av[i])
		{
			elmt->nbr = (t_stack *)av[i];
			ft_push(elmt, last);
			j = ft_pop(last);
			if (!j)
			{
				printf("%s\n", j->nbr);
				j = ft_pop(last);
			}
			i++;
		}
	}
	free(elmt);
	return (0);
}