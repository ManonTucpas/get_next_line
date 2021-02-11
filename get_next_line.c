/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:05:41 by mlecuyer          #+#    #+#             */
/*   Updated: 2020/12/04 15:59:57 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char buffer[BUFFER_SIZE + 1];
	static char *stock[256];

	len_read = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (ft_strchr(stock[fd], '\n') == 0 &&
		((len_read = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		buffer[len_read] = '\0';
		ft_getstock(&stock[fd], buffer);
	}
	if (len_read == -1)
		return (-1);
	*line = ft_line(stock[fd]);
	if (*line == NULL)
		*line = ft_strdup("");
	stock[fd] = ft_new_stock(stock[fd]);
	if (len_read == 0)
		return (0);
	return (1);
}
int main()
{
	int fd;
	char *line;

	line = '\0';
	fd = open("test.txt", O_RDONLY);
	if(fd == -1)
	{
		printf("Open failed\n");
		return (-1);
	}
	printf("retour gnl = %i\n", get_next_line(fd, &line));
	printf("line = %s\n", line);
	free(line);
	printf("retour gnl = %i\n", get_next_line(fd, &line));
	printf("line = %s\n", line);
	free(line);
	printf("retour gnl = %i\n", get_next_line(fd, &line));
	printf("line = %s\n", line);
	free(line);
	printf("retour gnl = %i\n", get_next_line(fd, &line));
	printf("line = %s\n", line);
	free(line);
	printf("retour gnl = %i\n", get_next_line(fd, &line));
	printf("line = %s\n", line);
	free(line);
	printf("retour gnl = %i\n", get_next_line(fd, &line));
	printf("line = %s\n", line);
	free(line);
	printf("retour gnl = %i\n", get_next_line(fd, &line));
	printf("line = %s\n", line);
	free(line);
	printf("retour gnl = %i\n", get_next_line(fd, &line));
	printf("line = %s\n", line);
	free(line);
	if(close(fd) == -1)
		return (-1);
	return (0);
}