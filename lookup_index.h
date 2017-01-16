/*
 * Multi level lookup index API.
 *
 * Copyright (c) 2017 Roman Storozhenko <romeusmeister@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 */

/*
 * Module's internal structures that maintain indexes
 */

typedef struct cch_index_entry {
	int ref_cnt;
	struct cch_index_entry *parent;
	struct list_head index_lru_list_entry;
	union {
		uint64_t backend_dev_offs;
		struct cch_index_entry *entry;
	void *value;
	} v[];
} cch_index_entry;

typedef struct cch_index {
	spinlock_t cch_index_value_lock;
	struct list_head index_lru_list;
	struct cch_index_entry head;
} cch_index;


/*
 * Module's public interface
 */

int cch_index_create(int levels, int bits, int root_bits, int low_bits,
		     cch_index **out);
void cch_index_destroy(struct cch_index *index);

int cch_index_find(cch_index *index, uint64_t key, void **out_value,
		   cch_index_entry **index_entry, int *value_offset);

int cch_index_find_direct(cch_index_entry *entry, int offset, void **out_value,
			  cch_index_entry **next_index_entry,
			  int *value_offset);

int cch_index_insert(cch_index *index, uint64_t key, void *value, bool replace,
		     cch_index_entry **new_index_entry, int *new_value_offset);

int cch_index_insert_direct(cch_index_entry *entry, bool replace, void *value,
			    cch_index_entry **new_index_entry,
			    int *new_value_offset);

int cch_index_remove(cch_index *index, uint64_t key);

int cch_index_remove_direct(cch_index_entry *entry, int offset);

int cch_index_shrink(cch_index_entry *index, int max_mem_kb);
