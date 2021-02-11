/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:33:39 by mlecuyer          #+#    #+#             */
/*   Updated: 2020/12/01 18:02:00 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t			ft_lens1s2(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	return (len_s1 + len_s2);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_lens1s2(s1, s2) + 1));
	if (!new_str)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char			*ft_strdup(const char *s1)
{
	char	*dup;
	int		size_s1;
	int		i;

	size_s1 = 0;
	i = 0;
	while (s1[size_s1])
		size_s1++;
	dup = (char *)malloc(sizeof(char) * size_s1 + 1);
	if (dup == NULL)
		return (0);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	char	*tmp_s;

	i = 0;
	if (!s)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (new_str);
	tmp_s = (char *)s;
	while (tmp_s[start] && i < len)
	{
		new_str[i] = tmp_s[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}
