/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:43:02 by adecauch          #+#    #+#             */
/*   Updated: 2024/12/17 07:39:01 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	checkn(char *src)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
	{
		if (src[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*end(char **tmp)
{
	char	*line;

	if (*tmp && *tmp[0])
	{
		line = ft_strndup(*tmp, ft_strlen(*tmp));
		free(*tmp);
		*tmp = NULL;
		return (line);
	}
	free(*tmp);
	*tmp = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			rd;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*ntmp;
	static char	*tmp = NULL;

	if (!tmp)
		tmp = ft_strndup("", 1);
	while (!checkn(tmp))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
			return (end(&tmp));
		buffer[rd] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	line = ft_strndup(tmp, (checkn(tmp)));
	ntmp = ft_strndup((tmp + checkn(tmp)), ft_strlen(tmp + checkn(tmp)));
	free (tmp);
	tmp = ntmp;
	return (line);
}