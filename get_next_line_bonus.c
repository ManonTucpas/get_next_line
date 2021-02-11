/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:39:20 by mlecuyer          #+#    #+#             */
/*   Updated: 2020/12/02 11:16:29 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (0);
}

static char		*ft_line(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	while (s[i])
	{
		if (s[i] == '\n')
			return (ft_substr(s, 0, i));
		i++;
	}
	return (ft_strdup(s));
}

static char		*ft_new_stock(char *s)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[j])
		j++;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i] || !s[i + 1])
	{
		free(s);
		s = NULL;
		return (NULL);
	}
	i++;
	tmp = ft_substr(s, i, j - i);
	free(s);
	s = NULL;
	return (tmp);
}

static void		ft_getstock(char **stock, char *buffer)
{
	char *tmp;

	if (*stock == NULL)
		tmp = ft_strdup(buffer);
	else
		tmp = ft_strjoin(*stock, buffer);
	if (*stock)
		free(*stock);
	*stock = tmp;
}

int				get_next_line(int fd, char **line)
{
	int			len_read;
	char		buffer[BUFFER_SIZE + 1];
	static char *str_stock[256];

	len_read = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (ft_strchr(str_stock[fd], '\n') == 0 &&
		((len_read = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		buffer[len_read] = '\0';
		ft_getstock(&str_stock[fd], buffer);
	}
	if (len_read == -1)
		return (-1);
	*line = ft_line(str_stock[fd]);
	if (*line == NULL)
		*line = ft_strdup("");
	str_stock[fd] = ft_new_stock(str_stock[fd]);
	if (len_read == 0)
		return (0);
	return (1);
}
