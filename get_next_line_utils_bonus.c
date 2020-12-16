#include "get_next_line_bonus.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (0);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2 || !(new_str = malloc(sizeof(char) *
			(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_strrchr(char *str, int c)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
	{
		if (*(str + idx) == c)
			return ((char *)(str + idx));
		idx++;
	}
	return (0);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}
