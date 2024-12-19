/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:43:59 by adecauch          #+#    #+#             */
/*   Updated: 2024/12/17 07:43:58 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE//Si buffer size pas defini avec -D
#  define BUFFER_SIZE 128//Alors buffersize est defini et est egale a 128
# endif

# include <unistd.h>//read
# include <stddef.h>//size_t
# include <stdlib.h>//malloc

/*-----get_next_line.c-----*/

size_t	checkn(char *src);
char	*end(char **tmp);
char	*get_next_line(int fd);

/*-----get_next_line_utils.c-----*/

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t lendst);
char	*ft_strndup(const char *src, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
