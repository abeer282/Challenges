#include <stdio.h>
#include <stdbool.h> 


typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}Node;

typedef struct message {
	int source;
	int destination;
}Message;

enum Validity {Valid, Invalid};


Node* create_node(int data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}


Node* insert(Node* root, int data) {
	if (root == NULL)
		return create_node(data);
	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);
	return root;
}


bool search(Node* root, int spam) {
	if (root != NULL) {
		if (root->data == spam)
			return true;
		else if (root->data > spam)
			return search(root->left, spam);
		else
			return search(root->right, spam);
	}
	else {
		return false;
	}
}


enum Validity spammed_message(Node* root, Message msg) {
	if (search(root, msg.source) || search(root, msg.destination))
		return Invalid;
	return Valid;
}


void in_order(Node* root) {
	if (root != NULL) {
		in_order(root->left);
		printf("%d ", root->data);
		in_order(root->right);
	}
}

int main() {
	Node* root = NULL;
	Message msg = {1,11};

	root = insert(root, 9);
	insert(root, 7);
	insert(root, 3);
	insert(root, 8);
	insert(root, 1);
	insert(root, 11);
	insert(root, 5);
	insert(root, 2);

	printf("%d\n", spammed_message(root, msg));

	in_order(root);
	getchar();
	return 0;
}

