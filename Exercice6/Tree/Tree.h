#ifndef TREE_H
#define TREE_H
#include "../Bank/Bank.h" //Importei para que as funções print_item e get_key fizessem sentido, não sei como resolver isso
#include "../Util/util.h"

typedef CPF TYPE_KEY; //necessário definir

typedef struct binary_tree_st BINARY_TREE;

BINARY_TREE *create_tree();
boolean insert_tree(BINARY_TREE *tree, void *item) ;
boolean erase_tree(BINARY_TREE **tree);
boolean remove_tree(BINARY_TREE *tree, TYPE_KEY key);
BANK *search_tree(BINARY_TREE *tree, TYPE_KEY key);
void pre_order_tree(BINARY_TREE *tree);
void in_order_tree(BINARY_TREE *tree);
void pos_order_tree(BINARY_TREE *tree);

#endif // TREE_H