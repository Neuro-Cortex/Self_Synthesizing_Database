#ifndef SSDB_H
#define SSDB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    INT,
    FLOAT,
    STRING,
    NODE_LINK 
} DataType;


typedef struct SSDB_Node {
    int id;
    char key[50];
    DataType type;
    void* value; 
    
    er sathe link thakte pare (Graph)
    struct SSDB_Node** neighbors;
    int neighbor_count;
    
   
    int access_count; 
} SSDB_Node;


SSDB_Node* create_node(int id, const char* key, DataType type, void* val);
void link_nodes(SSDB_Node* src, SSDB_Node* dest);

