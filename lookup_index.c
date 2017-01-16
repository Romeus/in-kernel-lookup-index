/* GPL HEADER START
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 only,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License version 2 for more details (a copy is included
 * in the LICENSE file that accompanied this code).
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with this program; If not, see http://www.gnu.org/licenses
 *
 * Please  visit http://www.xyratex.com/contact if you need additional
 * information or have any questions.
 *
 * GPL HEADER END
 */

/*
 * Copyright 2017 Roman Storozhenko <romeusmeister@gmail.com>
 */

/*
 * This is module that maintains multi level lookup index
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include "lookup_index.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Roman Storozhenko <romeusmeister@gmail.com>");
MODULE_DESCRIPTION("MultiLevel Lookup Index Module");


static int __init hello_init(void)
{
    printk(KERN_INFO "Initialize multilevel_index_lookup module!\n");
    return 0;
}

static void __exit hello_cleanup(void)
{
    printk(KERN_INFO "Cleaning up multilevel_index_lookup module.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);
