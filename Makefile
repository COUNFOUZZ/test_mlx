# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabda <aabda@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 16:40:00 by aabda             #+#    #+#              #
#    Updated: 2022/08/31 17:27:47 by aabda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
MLX		= ./minilibx/libmlx.a
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
MFLAGS	= -L./minilibx -lmlx -framework OpenGL -framework AppKit
SRCS 	= main.c
OBJS 	= $(SRCS:.c=.o)

all: $(MLX) $(NAME)

$(MLX):
	make -sC ./minilibx

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MFLAGS) -o $(NAME)

norm:
	norminette -R CheckDefine

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make clean -C ./minilibx

re: fclean all

.PHONY:	all clean fclean re norm