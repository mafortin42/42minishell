/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:44:24 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/21 14:45:28 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ms_saved_fd(void)
{
	g_ms.stdin = dup(0);
	g_ms.stdout = dup(1);
}

void	ms_return_fd(void)
{
	dup2(g_ms.stdin, 0);
	dup2(g_ms.stdout, 1);
}

bool	ms_exec_phase(t_job *current)
{
	bool	pipe;

	g_ms.exec = 1;
	if (current->next)
		pipe = true;
	else
		pipe = false;
	if (pipe == false)
	{
		if (ms_check_builtin(current) == false)
			return (ms_exec_fork(current));
	}
	return (ms_pipe_exec(current));
}

void	ms_exec_main(t_job *job_head)
{
	t_job	*current;

	current = job_head;
	while (current)
	{
		ms_saved_fd();
		dollarsign_main(current);
		if (ms_redirection_main(current) == false)
		{
			g_ms.exit = 127;
			return ;
		}
		trimquotes_main(current);
		if (ms_exec_phase(current) == false)
			return (ms_return_fd());
		if (current->next)
			current = current->next;
		return (ms_return_fd());
	}
}
