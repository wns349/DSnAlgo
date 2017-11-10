#include <stdio.h>
#define MAX_HEAP 1000
#define MAX_HASH 10

typedef struct _Node {
	int value;
	_Node* next = NULL;
} Node;

Node mem[MAX_HEAP];	// memory
Node* hash[MAX_HASH]; // hash table
int memCount = 0;

int main() {
	// init hash table
	for (int i = 0; i < MAX_HASH; i++) {
		hash[i] = NULL;
	}

	// add numbers to hash table
	// assume mem is large enough to fit every data
	for (int i = 0; i < 555; i++) {
		// get hash
		int hashIdx = i % MAX_HASH;
		mem[memCount].value = i;
		mem[memCount].next = hash[hashIdx];
		hash[hashIdx] = &mem[memCount];	// always append to head
		memCount++;
	}

	// print hash table
	for (int i = 0; i < MAX_HASH; i++) {
		printf("%3d: ", i);
		for (Node* n = hash[i]; n != NULL; n = n->next) {
			printf("%d ", n->value);
		}
		printf("\n");
	}

	printf("Done.\n");
	return 0;
}