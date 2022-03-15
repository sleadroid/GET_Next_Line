/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkivilah <nkivilah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 21:58:57 by nkivilah          #+#    #+#             */
/*   Updated: 2021/11/16 12:48:51 by nkivilah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	x;
	size_t			i;
	char			*ptr;

	ptr = s;
	i = 0;
	x = c;
	while (i < n)
	{
		*(ptr + i) = x;
		i++;
	}
	return (ptr);
}
