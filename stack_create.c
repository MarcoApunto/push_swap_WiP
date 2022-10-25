// Make stack and add values (int)
// Will need putnbr (uses putstr and putchar...)????

#include <stdlib.h>
#include <stdio.h>
int	ft_atoi(const char *str);

// stack of int
typedef struct s_stack{
	int				nbr;
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

	if (last == NULL)
		return (NULL);
	content = last;
	last = content->next;
	return (content);
}

int main(int ac, char **av)
{
	size_t	i;
	t_stack	*pushed;
	t_stack	*last;
	t_stack	*elmt;

	elmt = malloc(sizeof(t_stack));
	if (!elmt)
		return (0);
	last = NULL;
	i = 1;
	if (ac > 1)
	{	
		while(av[i])
		{
			elmt->nbr = ft_atoi(av[i]);
			ft_push(elmt, last);
			pushed = ft_pop(last);
			if (pushed != NULL) 
			{
				printf("%d\n", pushed->nbr);
				pushed = ft_pop(last);
			}
			i++;
		}
	}
	free(elmt);
}


static unsigned long long int	ft_check_long(int x, unsigned long long int y)
{
	unsigned long long int	lngn;

	lngn = 9223372036854775806;
	if (y > lngn && x > 0)
		return (-1);
	if (y > lngn + 1 && x < 0)
		return (0);
	return (y);
}

int	ft_atoi(const char *str)
{
	int						c;
	int						x;
	unsigned long long int	y;

	c = 0;
	x = 1;
	y = 0;
	while ((str[c] >= 9 && str[c] <= 13) || str[c] == 32)
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			x *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		y = (str[c] - '0') + (y * 10);
		c++;
	}
	y = ft_check_long(x, y);
	return (x * y);
}