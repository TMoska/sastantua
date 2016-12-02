CC = gcc
FLAGS = -Wall -Werror -Wextra -I.
NAME = sastantua
SOURCES = utils/ft_atoi.c utils/ft_putchar.c main.c sastantua.c

all: $(NAME)

$(NAME): $(SOURCES)
	@$(CC) $(FLAGS) $(SOURCES) -o $(NAME)
	@echo "\033[0;32mSuccess: \033[0mmake done"
	
clean:
	@find . \( -name "*~" -o -name "*.swp" -o -name ".DS_Store" \) -delete

fclean: clean
	@rm -f $(NAME)

re: fclean all
