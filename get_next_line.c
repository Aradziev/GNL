/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleradzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:11:44 by aleradzi          #+#    #+#             */
/*   Updated: 2019/09/13 16:31:02 by aleradzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			dolessthings(int fd, char **line, char **fdarray)
{
	*line = ft_strdup(fdarray[fd]);
	ft_strdel(&fdarray[fd]);
	return (1);
}

int			dothings(int fd, char **line, char **fdarray)
{
	int		i;
	int		g;
	char	*buffer;

	buffer = NULL;
	g = ft_strlen(fdarray[fd]);
	i = 0;
	while (fdarray[fd][i] != '\n')
		i++;
	*line = ft_strsub(fdarray[fd], 0, i);
	if (g <= i + 1)
	{
		ft_strdel(&fdarray[fd]);
		return (1);
	}
	buffer = ft_strdup(fdarray[fd] + (i + 1));
	ft_strdel(&fdarray[fd]);
	fdarray[fd] = buffer;
	if (ft_strlen(fdarray[fd]) < 1)
		ft_strdel(&fdarray[fd]);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int				readsize;
	char			readbuffer[BUFF_SIZE + 1];
	char			*buffer;
	static char		*fdarray[MAX_FD];

	while ((readsize = read(fd, readbuffer, BUFF_SIZE)) > 0)
	{
		readbuffer[readsize] = '\0';
		if (fdarray[fd] == NULL)
			fdarray[fd] = ft_strnew(1);
		buffer = ft_strjoin(fdarray[fd], readbuffer);
		ft_strdel(&fdarray[fd]);
		fdarray[fd] = buffer;
		if ((ft_strchr(fdarray[fd], '\n') != NULL))
			return (dothings(fd, line, fdarray));
	}
	if (readsize < 0 || BUFF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (readsize == 0 && (fdarray[fd] == NULL || fdarray[fd][0] == '\0'))
		return (0);
	if ((ft_strchr(fdarray[fd], '\n') != NULL))
		return (dothings(fd, line, fdarray));
	return (dolessthings(fd, line, fdarray));
}
