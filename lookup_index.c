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
 * This module implements multi level lookup index
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include "lookup_index.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Roman Storozhenko <romeusmeister@gmail.com>");
MODULE_DESCRIPTION("MultiLevel Lookup Index Module");

/*
 * Implementation of the module's public interface
 */

int cch_index_create(int levels, int bits, int root_bits, int low_bits,
		     cch_index **out)
{
	return 0;
}

void cch_index_destroy(struct cch_index *index)
{
}

int cch_index_find(cch_index *index, uint64_t key, void **out_value,
		   cch_index_entry **index_entry, int *value_offset)
{
	return 0;
}

int cch_index_find_direct(cch_index_entry *entry, int offset, void **out_value,
			  cch_index_entry **next_index_entry,
			  int *value_offset)
{
	return 0;
}

int cch_index_insert(cch_index *index, uint64_t key, void *value, bool replace,
		     cch_index_entry **new_index_entry, int *new_value_offset)
{
	return 0;
}

int cch_index_insert_direct(cch_index_entry *entry, bool replace, void *value,
			    cch_index_entry **new_index_entry,
			    int *new_value_offset)
{
	return 0;
}

int cch_index_remove(cch_index *index, uint64_t key)
{
	return 0;
}

int cch_index_remove_direct(cch_index_entry *entry, int offset)
{
	return 0;
}

int cch_index_shrink(cch_index_entry *index, int max_mem_kb)
{
	return 0;
}

/*
 * Export module's public API to kernel
 */

EXPORT_SYMBOL_GPL(cch_index_create);
EXPORT_SYMBOL_GPL(cch_index_destroy);
EXPORT_SYMBOL_GPL(cch_index_find);
EXPORT_SYMBOL_GPL(cch_index_find_direct);
EXPORT_SYMBOL_GPL(cch_index_insert);
EXPORT_SYMBOL_GPL(cch_index_insert_direct);
EXPORT_SYMBOL_GPL(cch_index_remove);
EXPORT_SYMBOL_GPL(cch_index_remove_direct);
EXPORT_SYMBOL_GPL(cch_index_shrink);

/*
 * Module's initialization code
 */

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
