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
 * This module implements a set of unit tests for multi level lookup index
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include "../lookup_index.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Roman Storozhenko <romeusmeister@gmail.com>");
MODULE_DESCRIPTION("A set of unit tests for MultiLevel Lookup Index Module");


/*
 * Unit tests
 */

void test_success_index_create(void)
{
	cch_index **out;
	int err_code = cch_index_create(5, 10, 5, 5, out);
	printk(KERN_INFO "returned error code is %d", err_code);
}

/*
 * Module's initialization code
 */

static int __init lookup_unittests_init(void)
{
    printk(KERN_INFO "---------------------------------------------------------");
    printk(KERN_INFO "Initialize unit tests for multilevel_index_lookup module!\n");
    printk(KERN_INFO "Calling test_success_index_create");
    test_success_index_create();

    return 0;
}

static void __exit lookup_unittests_cleanup(void)
{
    printk(KERN_INFO "Cleaning up unit tests for  multilevel_index_lookup module.\n");
    printk(KERN_INFO "---------------------------------------------------------");
}

module_init(lookup_unittests_init);
module_exit(lookup_unittests_cleanup);
