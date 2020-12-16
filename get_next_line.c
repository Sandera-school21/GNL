#include "get_next_line.h"

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

char	*prov_ost(char *ost, char **line)
{
	char *point;

	point = NULL;
	if (ost)
		if ((point = ft_strrchr(ost, '\n')))
		{
			*point = '\0';
			*line = ft_strdup(ost);
			ft_strcpy(ost, ++point);
		}
		else
		{
			*line = ft_strdup(ost);
			ft_strclr(ost);
		}
	else
		*line = ft_strnew(1);
	return (point);
}

int		ft_check_read(int w_r, char *ost, char **line)
{
	if (w_r == 0)
		return (0);
	if (w_r < 0)
		return (-1);
	if (ft_strlen(*line) == 0)
		return (1);
	if (ost != NULL)
		return (1);
	if (ost == NULL)
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int				w_r;
	static char		*ost;
	char			buf[BUFFER_SIZE + 1];
	char			*point;
	char			*vrem;

	if (!line || read(fd, 0, 0) || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	point = prov_ost(ost, line);
	while (!point && (w_r = read(fd, buf, BUFFER_SIZE)))
	{
		buf[w_r] = '\0';
		if ((point = ft_strrchr(buf, '\n')))
		{
			*point = '\0';
			point++;
			ost = ft_strdup(point);
		}
		vrem = *line;
		*line = ft_strjoin(*line, buf);
		free(vrem);
	}
	return (ft_check_read(w_r, ost, line));
}
