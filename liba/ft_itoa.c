/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:05:41 by thalfemp          #+#    #+#             */
/*   Updated: 2019/09/16 09:42:56 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len(long long nb)
{
	int len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		len++;
	}
	if (nb >= 0 && nb <= 9)
	{
		len++;
		return (len);
	}
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int			i;
	char		*str;
	int			j;
	int			k;
	long long	nb;

	j = len(n);
	k = len(n);
	nb = n;
	if (!(str = (char*)malloc(sizeof(*str) * (len(n) + 1))))
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		str[i++] = '-';
	}
	while (j != i)
	{
		str[j - 1] = (nb % 10) + '0';
		nb = nb / 10;
		j--;
	}
	str[k] = '\0';
	return (str);
}
