#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define BUBBLE 1000000

using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

// A utility function to create a new BST Node
struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Stores inoder traversal of the BST
// in arr[]
void storeSorted(Node *root, int arr[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}

/* A utility function to insert a new
 Node with given key in BST */
Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key);
    
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    /* return the (unchanged) Node pointer */
    return node;
}

// This function sorts arr[0..n-1] using Tree Sort
void treeSort(int arr[], int n)
{
    struct Node *root = NULL;
    
    // Construct the BST
    root = insert(root, arr[0]);
    for (int i=1; i<n; i++)
        insert(root, arr[i]);
    
    // Store inoder traversal of the BST
    // in arr[]
    int i = 0;
    storeSorted(root, arr, i);
}

// Driver Program to test above functions
int main()
{
    clock_t t;
    int arr[BUBBLE];
    int i, num;
    for (i = 0; i < BUBBLE; i ++)
    {
        num = rand() % BUBBLE + 1;
        arr[i] = num;
    }
    
    t = clock();
    treeSort(arr, BUBBLE);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("%f ms \n", time_taken*1000);
    
    return 0;
}
