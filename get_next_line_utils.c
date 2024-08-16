/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:05:07 by divalent          #+#    #+#             */
/*   Updated: 2024/02/05 15:31:34 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	count_to_newline(char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
	{
		if (s[len] == '\n')
			return (len + 1);
		len++;
	}
	return (len);
}

void	*buff_cleaner(char *buff, int *check, int funct)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	*check = 0;
	if (funct <= 0)
	{
		free(buff);
		return (NULL);
	}
	while (i < BUFFER_SIZE)
	{
		if (*check == 1 && funct == 2)
			buff[j++] = buff[i];
		if (buff[i] == '\n' && funct == 2)
			*check = 1;
		buff[i] = 0;
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	len1;
	size_t	len2;
	size_t	len3;

	len1 = count_to_newline(s1);
	len2 = count_to_newline(s2);
	len3 = 0;
	s3 = (char *) malloc(len1 + len2 + 1);
	if (!s3)
		return (s1);
	len1 = 0;
	len2 = 0;
	while (s1 && s1[len1])
		s3[len3++] = s1[len1++];
	while (s2 && s2[len2] && s2[len2] != '\n')
		s3[len3++] = s2[len2++];
	if (s2[len2] == '\n')
		s3[len3++] = '\n';
	free(s1);
	s3[len3] = '\0';
	return (s3);
}

char	*find_newline(char *buffer, int *check, char *line)
{
	line = ft_strjoin(line, buffer);
	if (!line)
		return (NULL);
	buff_cleaner(buffer, check, 2);
	return (line);
}
