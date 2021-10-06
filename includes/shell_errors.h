/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:12:17 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/06 09:48:20 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_ERRORS_H
# define SHELL_ERRORS_H

# define NO_ERROR 0
# define BAD_SYNTAX 2
# define NO_EXEC_CMD 126
# define CMD_NOT_FOUND 127
# define INV_ARG 128
# define CTRL_C	130

# define NAME "minishell: "
# define UNXP_TOKEN "syntax error near unexpected token"
# define ARGS_COUNT "Too many arguments"
# define S_QUOTE_ERR "unexpected EOF while looking for matching `\'"
# define D_QUOTE_ERR "unexpected EOF while looking for matching `\""

void	bad_quotes_syntax(t_parser *par);

#endif
