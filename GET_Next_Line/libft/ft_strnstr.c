/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkivilah <nkivilah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:52:03 by nkivilah          #+#    #+#             */
/*   Updated: 2021/12/01 20:11:14 by nkivilah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	len;

	if (!*needle)
		return ((char *)haystack);
	len = ft_strlen(needle);
	while (*haystack && n >= len)
	{
		if (*needle == *haystack
			&& ft_strncmp(needle, haystack, len) == 0)
			return ((char *)haystack);
		haystack++;
		n--;
	}
	return (NULL);
}
