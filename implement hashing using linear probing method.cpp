#include <stdio.h>
#define TABLE_SIZE 10
struct KeyValue {
    int key;
    int value;
};
struct KeyValue hashTable[TABLE_SIZE];
void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = -1;
    }
}
int hashFunction(int key) {
    return key % TABLE_SIZE;
}
void insert(int key, int value) {
    int index = hashFunction(key);
    while (hashTable[index].key != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index].key = key;
    hashTable[index].value = value;
}
int search(int key) {
    int index = hashFunction(key);
    while (hashTable[index].key != key) {
        if (hashTable[index].key == -1) {
            return -1; // Key not found
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return hashTable[index].value;
}
void display() {
    printf("Hash Table:\n");
    printf("-----------\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].key != -1) {
            printf("Index %d: Key = %d, Value = %d\n", i, hashTable[i].key, hashTable[i].value);
        }
    }
}
int main() {
    initializeHashTable();
    insert(15, 150);
    insert(25, 250);
    insert(35, 350);
    insert(45, 450);
    display();
    int keyToSearch = 25;
    int searchResult = search(keyToSearch);
    if (searchResult != -1) {
        printf("Value for key %d: %d\n", keyToSearch, searchResult);
    } else {
        printf("Key %d not found in the hash table.\n", keyToSearch);
    }

    return 0;
}