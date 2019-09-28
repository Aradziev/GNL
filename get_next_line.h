/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleradzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:13:22 by aleradzi          #+#    #+#             */
/*   Updated: 2019/09/13 16:27:14 by aleradzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 15
# define MAX_FD 4092
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		dolessthings(int fd, char **line, char **fdarray);
int		dothings(int fd, char **line, char **fdarray);
int		get_next_line(const int fd, char **str);

#endif
