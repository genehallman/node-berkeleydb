/*-
 * Copyright (c) 2012, 2020 Oracle and/or its affiliates.  All rights reserved.
 *
 * See the file LICENSE for license information.
 *
 * $Id$
 */

#include "db_config.h"

#include "db_int.h"

/*
 * remove implementation on WinCE.
 *
 * PUBLIC: #ifdef DB_WINCE
 * PUBLIC: int __ce_remove __P((const char *path));
 * PUBLIC: #endif
 */

int
__ce_remove(path)
	const char *path;
{
	return __os_unlink(NULL, path, 0);
}
