/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkivilah <nkivilah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 11:05:11 by nkivilah          #+#    #+#             */
/*   Updated: 2022/01/10 08:58:08 by nkivilah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** █▀▀▀▀ █▀▀▀▀ ▀▀█▀▀ ░░░░░ █▀▀▀▄ █▀▀▀▀ █░░░█ ▀▀█▀▀ ░░░░░ █░░░░ ▀▀█▀▀ █▀▀▀▄ █▀▀▀▀
** █░▀▀█ █▀▀░░ ░░█░░ ░░░░░ █░░░█ █▀▀░░ ▄▀▀▀▄ ░░█░░ ░░░░░ █░░░░ ░░█░░ █░░░█ █▀▀░░
** ▀▀▀▀▀ ▀▀▀▀▀ ░░▀░░ ▀▀▀▀▀ ▀░░░▀ ▀▀▀▀▀ ▀░░░▀ ░░▀░░ ▀▀▀▀▀ ▀▀▀▀▀ ▀▀▀▀▀ ▀░░░▀ ▀▀▀▀▀
**
** The output function detects the first \n or \0.
** If \n found, create substr of arr[fd] (from 0 to len).
** Make line point to new substr. strdup remainder of arr[fd] into temp.
** len + 1 to skip the \n. strdel arr[fd] and assign temp into arr[fd]
** (remainder after \n). Check if arr[fd] is empty then strdel it if true.
** If \n wasn't detected, line points to strdup of arr[fd] then strdel arr[fd].
*/

static int	output(int fd, char **line, char **arr)
{
	int		len;
	char	*temp;

	len = 0;
	while (arr[fd][len] != '\n' && arr[fd][len] != '\0')
		len++;
	if (arr[fd][len] == '\n')
	{
		*line = ft_strsub(arr[fd], 0, len);
		temp = ft_strdup(arr[fd] + len + 1);
		ft_strdel(&arr[fd]);
		arr[fd] = temp;
		if (arr[fd][0] == '\0')
			ft_strdel(&arr[fd]);
	}
	else
	{
		*line = ft_strdup(arr[fd]);
		ft_strdel(&arr[fd]);
	}
	return (1);
}

/*
** The get_next_line function reads a line from fd.
** -1 = errors | 1 = line read | 0 reading completed.
** While there's something to read, strjoin buff(read chars) and arr[fd]
** into temp, strdel arr[fd] and assign joined string to arr[fd].
** Break loop if \n found in the read string.
*/

int	get_next_line(const int fd, char **line)
{
	int			i;
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	static char	*arr[FD_SIZE];

	if (fd < 0 || line == NULL || fd > FD_SIZE)
		return (-1);
	i = read(fd, buff, BUFF_SIZE);
	while (i > 0)
	{
		buff[i] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = ft_strnew(1);
		temp = ft_strjoin(arr[fd], buff);
		ft_strdel(&arr[fd]);
		arr[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
		i = read(fd, buff, BUFF_SIZE);
	}
	if (i < 0)
		return (-1);
	if (i == 0 && arr[fd] == NULL)
		return (0);
	return (output(fd, line, arr));
}
