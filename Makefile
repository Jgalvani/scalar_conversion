# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 17:10:37 by jgalvani          #+#    #+#              #
#    Updated: 2017/08/24 15:38:40 by jgalvani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scalar_conversion

SRC_DIR = src

HDR_DIR = hdr

SRCS = main.cpp Type.cpp

HDRS = scalar.hpp Type.hpp

OBJ_DIR = objects

OBJS = $(SRCS:.cpp=.o)

SRC_PATH = $(addprefix $(SRC_DIR)/,$(SRCS))
HDR_PATH = $(addprefix $(HDR_DIR)/,$(HDRS))
OBJ_PATH = $(addprefix $(OBJ_DIR)/,$(OBJS))

FLGS = -Wall -Wextra -Werror

.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(SRC_PATH) $(HDR_PATH)
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	@echo "\033[0;40;32mCreating objects."
	@clang++ -c  $(FLGS) $(SRC_PATH)
	@mv $(OBJS) $(OBJ_DIR)
	@echo "Compiling" $(NAME)
	@clang++ $(FLGS) -o $(NAME) $(OBJ_PATH)
	@echo "\033[0m"

clean:
	@echo "\033[0;40;31mErasing objects."
	@rm -rf $(OBJ_PATH)
	@rmdir $(OBJ_DIR) 2> /dev/null || true
	@echo "\033[0m"

fclean:	clean
	@echo "\033[0;40;35mErasing" $(NAME)
	@rm -rf $(NAME)
	@echo "\033[0m"

re: fclean all
