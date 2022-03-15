/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkivilah <nkivilah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:44:58 by nkivilah          #+#    #+#             */
/*   Updated: 2021/11/23 22:38:11 by nkivilah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*source;
	unsigned char	ch;
	size_t			i;

	i = 0;
	d = (unsigned char *)dest;
	source = (unsigned char *)src;
	ch = (unsigned char)c;
	while (i < n)
	{
		d[i] = source[i];
		if (source[i] == ch)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
