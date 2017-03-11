/*
** get_next_line.c for get_next_line in /home/matthis.mecharle/rendu/PROG_ELEM/CPE_2017_getnextline
** 
** Made by Matthis Mecharle
** Login   <matthis.mecharle@epitech.net>
** 
** Started on  Sat Jan 14 12:26:12 2017 Matthis Mecharle
** Last update Sun Jan 15 17:15:12 2017 Matthis Mecharle
*/

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

char	*my_malloc(size_t size)
{
  int	i;
  char	*new;

  i = 0;
  if ((new = malloc(size)) == NULL)
    return (NULL);
  while (i < size)
    {
      new[i] = 0;
      i++;
    }
  return (new);
}

int	my_read(int fd, char *buffer, int readsize)
{
  int	i;

  i = 0;
  while (i < READ_SIZE)
    {
      buffer[i] = 0;
      i++;
    }
  return (read(fd, buffer, readsize));
}

char	*my_realloc(char *str, int size, char number_char)
{
  char	*number_str;
  int	i;

  i = 0;
  if ((number_str = my_malloc(sizeof(char) * (size + 2))) == NULL)
    return (NULL);
  while (i < size)
    {
      number_str[i] = str[i];
      i = i + 1;
    }
  number_str[i] = number_char;
  number_str[i + 1] = '\0';
  free(str);
  return (number_str);
}

char	*get_next_line(const int fd)
{
  static int  	i = 0;
  int		c;
  char		*count;
  static char	buffer[READ_SIZE + 1];
  
  c = 0;
  if ((count = my_malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  if (buffer[i] == '\0')
    if (my_read(fd, buffer, READ_SIZE) <= 0)
      return NULL;
  while (buffer[i] != '\n')
    {
      if (buffer[i] == '\0')
	{
	  if (my_read(fd, buffer, READ_SIZE) <= 0)
	    return (count);
	  else
	    i = 0;
	}
      if (buffer[i] != '\n')
	count = my_realloc(count, my_strlen(count), buffer[i]);
      else
	{
	  i = i + 1;
	  return (count);
	}
      i = i + 1;
      c = c + 1;
    }
  i = i + 1;
  return (count);
}
