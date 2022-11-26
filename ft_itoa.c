/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 07:58:08 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/12 19:29:19 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_var
{
	int			i;
	char		*str;
	long int	nb;

}				t_var;

static void	ft_strrev(char *str)
{
	int	i;
	int	tmp;
	int	len;

	len = ft_strlen(str);
	i = 0;
	if (str[i] == '-')
		i++;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		i++;
		len--;
	}
}

static char	*ft_alloc(long int n)
{
	int		nb;
	t_var	v;

	nb = 0;
	if (n == 0)
		nb++;
	if (n < 0)
		nb++;
	while (n != 0)
	{
		n = n / 10;
		nb++;
	}
	v.str = malloc (sizeof(char) * nb + 1);
	if (!v.str)
		return (NULL);
	return (v.str);
}

char	*ft_itoa(int n)
{
	t_var	v;

	v.nb = n;
	v.str = ft_alloc(n);
	if (!v.str)
		return (NULL);
	v.i = 0;
	if (v.nb == 0)
		v.str[v.i++] = '0';
	if (v.nb < 0)
	{
		v.nb = v.nb * (-1);
		v.str[v.i++] = '-';
	}
	while (v.nb > 0)
	{
		if (v.nb >= 0 && v.nb <= 9)
			v.str[v.i++] = v.nb + '0';
		if (v.nb >= 10)
			v.str[v.i++] = v.nb % 10 + '0';
		v.nb = v.nb / 10;
	}
	v.str[v.i] = '\0';
	ft_strrev(v.str);
	return (v.str);
}
