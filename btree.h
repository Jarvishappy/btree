#ifndef _BTREE_H
#define _BTREE_H

#include <stdio.h>

typedef int (*cmp_func_t)(void *key1, void *key2);

/**
 * Useless
 */
struct btree_node {
	void *key;
	void *value;
};

/**
 * 表示B-tree节点中的一个元素
 */
struct btree_item {
	void *key, *value;
	struct btree_table *child;
};

/**
 * 表示B-tree的一个node, 是一个数组, 其中每个元素是一个三元组(key, value, child)
 */
struct btree_table {
	size_t size;
	struct btree_item items[];
};

struct btree {
	struct btree_table *top;	/* 根节点 */
	cmp_func_t cmp;				/* 指定key的排序规则 */
	size_t max_keys;			/* key数量达到这个值时进行split */
};

void btree_init(struct btree *btree, cmp_func_t cmp, size_t num_keys);
void *btree_insert(struct btree *btree, void *key, void *value);
void *btree_get(struct btree *btree, void *key);
void *btree_delete(struct btree *btree, void *key);
size_t btree_depth(struct btree_table *table);

/* TODO */
void btree_dump(struct btree *btree);


#endif
