#include "../include/ssdb.h"

SSDB_Node* create_node(int id, const char* key, DataType type, void* val) {
    SSDB_Node* newNode = (SSDB_Node*)malloc(sizeof(SSDB_Node));
    if (newNode == NULL) return NULL;  
    

    newNode->id = id;
    strcpy(newNode->key, key);
    newNode->type = type;
    newNode->value = val;
    newNode->neighbor_count = 0;
    newNode->neighbors = NULL;
    newNode->access_count = 0;
    
    printf("[SSDB] Node Synthesized: %s\n", key);
    return newNode;
}

void link_nodes(SSDB_Node* src, SSDB_Node* dest) {
    src->neighbor_count++;
    src->neighbors = realloc(src->neighbors, sizeof(SSDB_Node*) * src->neighbor_count);
    src->neighbors[src->neighbor_count - 1] = dest;
    printf("[SSDB] Linked: %s -> %s\n", src->key, dest->key);
}

int main() {
    printf("--- SSDB Engine Initializing ---\n");

    
    int age = 25;
    SSDB_Node* userNode = create_node(1, "UserAge", INT, &age);
    
    
    char* location = "Bangladesh";
    SSDB_Node* locNode = create_node(2, "UserLocation", STRING, location);

    
    if (userNode != NULL && locNode != NULL) {
        link_nodes(userNode, locNode);
    }

    printf("--- SSDB Engine Running Successfully ---\n");

    
    return 0;
}