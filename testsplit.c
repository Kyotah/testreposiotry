/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatakey <khatakey@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:21:39 by khatakey          #+#    #+#             */
/*   Updated: 2021/04/17 19:09:22 by khatakey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen((char *)src);
	if (dstsize == 0)
		return (len_src);
	while ((i < dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

size_t	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}

char	*ft_write(char *dptr,char *str, size_t i, size_t cut_len)
{
	size_t	j;

	j = 0;
	while (cut_len > 0)
	{
		dptr[j] = str[i - cut_len];
		j++;
		cut_len--;
	}
	dptr[j] = '\0';
	return (dptr);
}

char	**ft_get_len(char **dptr, char *str, char c, size_t divide_num_str)
{
	size_t	i;
	size_t	j;
	size_t	cut_len;

	i = 0;
	j = 0;
	cut_len = 0;
	while (str[i] && j < divide_num_str)
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			cut_len++;
			i++;
		}
		if (!(dptr[j] = (char *)malloc(sizeof(char) * (cut_len + 1))))
			return (NULL);
		ft_write(dptr[j], str, i, cut_len);
		cut_len = 0;
		j++;
	}
	dptr[j] = 0;
	return (dptr);
}

size_t	ft_divide(char const *s, char c)
{
	size_t	i;
	size_t	divide_num_str;

	i = 0;
	divide_num_str = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			divide_num_str++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (divide_num_str);
}

char	**ft_split(char const *s, char c)
{
	char	**dptr;
	size_t	divide_num_str;
	char	*str;

	if (!s)
		return (NULL);
	divide_num_str = ft_divide(s, c);
	if (!(dptr = (char **)malloc(sizeof(char *) * (divide_num_str + 1))))
		return (NULL);
	str = (char *)s;
	ft_get_len(dptr, str, c, divide_num_str);
	return (dptr);
}

#include <stdio.h>
int	main(void)
{
	char	**tab;
	unsigned int	i;

	i = 0;
	// tab = ft_split("     split   this   for   me  ! ", ' ');
	tab = ft_split("xxaaabbbxrc", 'x');
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
