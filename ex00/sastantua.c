/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 09:28:47 by tmoska            #+#    #+#             */
/*   Updated: 2016/09/04 21:43:06 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		base_ln_len(int size, int floor_num)
{
	int line_diff;
	int i;

	if (floor_num == size)
		return (1);
	line_diff = 4;
	i = floor_num;
	while (i <= size)
	{
		if ((floor_num % 2 == 0) && (i % 2 == 1))
			line_diff += 4;
		else if (floor_num % 2 == 0)
			line_diff += 2;
		else if ((floor_num % 2 == 1) && (i % 2 == 1))
			line_diff += 2;
		else
			line_diff += 4;
		i++;
	}
	return (base_ln_len(size, floor_num + 1) + line_diff);
}

void	build_line(int length, int offset, int door_size, int door_knob)
{
	int len;
	int d_s;

	len = length;
	d_s = door_size;
	while (--offset >= 0)
		ft_putchar(' ');
	ft_putchar('/');
	if (door_size == 0)
		while (--length >= 0)
			ft_putchar('*');
	else
	{
		while (--length >= ((len - door_size) / 2 + door_size))
			ft_putchar('*');
		while (--d_s >= 0)
			if (door_knob && door_size > 3 && d_s == 1)
				ft_putchar('$');
			else
				ft_putchar('|');
		while (--length >= door_size - 1)
			ft_putchar('*');
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

void	build_floor_with_door(int size, int floor_num, int lvls, int length)
{
	int offset;
	int base_offset;
	int door_size;

	base_offset = ((base_ln_len(size, 1) - base_ln_len(size, floor_num)) / 2);
	door_size = size;
	if (size % 2 == 0)
		door_size--;
	while (--lvls > 0)
	{
		offset = base_offset + lvls - 7 + ((floor_num + 5));
		if (lvls > door_size)
			build_line(length, offset, 0, 0);
		else
		{
			if ((door_size / 2) == (door_size - lvls))
				build_line(length, offset, door_size, 1);
			else
				build_line(length, offset, door_size, 0);
		}
		length += 2;
	}
}

void	build_floor(int size, int floor_num)
{
	int levels;
	int offset;
	int length;
	int base_offset;

	levels = 3 + (size - floor_num);
	length = base_ln_len(size, floor_num);
	base_offset = ((base_ln_len(size, 1) - base_ln_len(size, floor_num)) / 2);
	while (levels > 0)
	{
		offset = base_offset + levels - 7 + ((floor_num + 5));
		build_line(length, offset, 0, 0);
		levels--;
		length += 2;
	}
}

void	sastantua(int size)
{
	int floor_num;
	int lvls;
	int length;

	floor_num = size;
	while (floor_num > 1)
	{
		build_floor(size, floor_num);
		floor_num--;
	}
	lvls = 4 + (size - floor_num);
	length = base_ln_len(size, floor_num);
	build_floor_with_door(size, floor_num, lvls, length);
}
