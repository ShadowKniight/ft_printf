NAME = libftprintf.a
RM = rm -f
CFLAGS = -Wextra -Werror -Wall
SRCS = 	ft_printf.c\
		ft_printf_helper.c

OBJECTS = $(SRCS:.c=.o)

all :	$(NAME)

$(NAME) :	$(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)
clean :
	$(RM) $(OBJECTS)
fclean : clean
	$(RM) $(NAME)
re : fclean clean all

.PHONY : all fclean clean re