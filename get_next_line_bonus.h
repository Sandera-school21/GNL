#ifndef GNL_GET_NEXT_LINE_BONUS_H
# define GNL_GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_S 4096

int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strrchr(char *str, int c);
char	*ft_strnew(size_t size);

#endif
