/*-
 * Copyright (c) 2005, 2020 Oracle and/or its affiliates.  All rights reserved.
 *
 * See the file LICENSE for license information.
 *
 * $Id$
 */

#include "db_config.h"

#include "db_int.h"

/*
 * __os_abort --
 *
 * PUBLIC: void __os_abort __P((const ENV *));
 */
void
__os_abort(env)
	const ENV *env;
{
	__os_stack(env);		/* Try and get a stack trace. */

#ifdef HAVE_ABORT
	abort();			/* Try and drop core. */
	/* NOTREACHED */
#endif
#ifdef SIGABRT
	(void)raise(SIGABRT);		/* Try and drop core. */
#endif
	exit(1);			/* Quit anyway. */
	/* NOTREACHED */
}
