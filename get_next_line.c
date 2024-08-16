/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:05:03 by divalent          #+#    #+#             */
/*   Updated: 2024/02/05 15:37:17 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	int				end;
	int				check;
	char			*line;

	check = 0;
	end = 0;
	line = NULL;
	while (BUFFER_SIZE > 0 && fd >= 0 && fd < FOPEN_MAX)
	{
		if (*buffer)
			line = find_newline(buffer, &check, line);
		if (buffer[0] == '\0' && check == 0)
		{
			end = read(fd, buffer, BUFFER_SIZE);
			if (end < 0)
				buff_cleaner(buffer, &check, 1);
			if ((end <= 0 && !line) || end < 0)
				return (buff_cleaner(line, &check, end));
			buffer[end] = '\0';
		}
		if ((line && check == 1) || (buffer[0] == '\0' && end == 0))
			return (line);
	}
	return (NULL);
}

/*
int main(void)
{
    int		fd;
	char	*line;
	char	c[1];

    fd = open("teste.txt", O_RDONLY);
	while((line = get_next_line(fd)))
    {
        printf("res: %s\n", line);
        free(line);
    }
	
	close(fd);
	return (0);
} */
