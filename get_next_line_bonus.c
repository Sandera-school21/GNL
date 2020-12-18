/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandera <sandera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:37:13 by sandera           #+#    #+#             */
/*   Updated: 2020/12/18 20:37:13 by sandera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*prov_ost(char **ost, char **line, int fd)
{
	char *point;

	point = NULL;
	if (ost[fd])
		if ((point = ft_strrchr(ost[fd], '\n')))
		{
			*point = '\0';
			*line = ft_strdup(ost[fd]);
			ft_strcpy(ost[fd], ++point);
		}
		else
		{
			*line = ft_strdup(ost[fd]);
			ft_strclr(ost[fd]);
		}
	else
		*line = ft_strnew(1);
	return (point);
}

int		ft_check_read(int w_r, char **ost, int fd)
{
	if (w_r < BUFFER_SIZE && !ost[fd] && w_r != -1)
		return (0);
	if (w_r < 0)
		return (-1);
	if (w_r == 0)
		return (0);
	if (ost[fd] == NULL)
		return (0);
	if (w_r == -1)
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int				w_r;
	static char		*ost[MAX_S];
	char			buf[BUFFER_SIZE + 1];
	char			*point;
	char			*vrem;

	if (!line || read(fd, 0, 0) || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	point = prov_ost(ost, line, fd);
	w_r = 1;
	while (!point && (w_r = read(fd, buf, BUFFER_SIZE)))
	{
		buf[w_r] = '\0';
		if ((point = ft_strrchr(buf, '\n')))
		{
			*point = '\0';
			ost[fd] = ft_strdup(++point);
		}
		vrem = *line;
		*line = ft_strjoin(*line, buf);
		free(vrem);
	}
	return (ft_check_read(w_r, ost, fd));
}
