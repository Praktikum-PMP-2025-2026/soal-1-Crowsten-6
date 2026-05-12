/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 5 – Foundation of Algorithm
 *   Hari dan Tanggal    : Selasa 12 Mei 2026
 *   Nama (NIM)          : Jonathan Chandra (13224103)
 *   Nama File           : Soal2.c
 *   Deskripsi           :  Penggabungan Dua Jalur Terurut
 * 
 */

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 struct Node {
    int data;
    struct Node* kiri;
    struct Node* kanan;
 };

 struct Node* newnode (int x) {
    struct Node* node  = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->kiri = NULL;
    node->kanan = NULL;
    return node;
 }

struct Node* insert(int arr[], struct Node* root, int i, int n) {
    if (i < n) {
        struct Node* temp = newnode(arr[i]);
        root = temp;

        root->kiri = insert(arr, root->kiri, 2 * i + 1, n);

        root->kanan = insert(arr, root->kanan, 2 * i + 2, n);
    }
    return root;
}

 void preOrder(struct Node* node) {
    if (node == NULL)
        return;

    printf(" %d", node->data);
    preOrder(node->kiri);
    preOrder(node->kanan);

}

void postOrder(struct Node *node)
{
    if (node == NULL)
        return;

    postOrder(node->kiri);
    postOrder(node->kanan);
    printf(" %d", node->data);
}

void inOrder(struct Node* node) {
    if (node == NULL)
        return;
        
    inOrder(node->kiri); 
    printf(" %d", node->data); 
    inOrder(node->kanan);
}

int main() {
    int N;

    if (scanf("%d", &N) != 1) return 0;
    int arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = insert(arr,NULL,0,N);

    printf("PRE "); 
    preOrder(root); printf("\n");
    printf("IN "); 
    inOrder(root); printf("\n");
    printf("POST "); 
    postOrder(root); printf("\n");

    return 0;
}


// https://www.geeksforgeeks.org/dsa/preorder-traversal-of-binary-tree/
// https://www.geeksforgeeks.org/dsa/postorder-traversal-of-binary-tree/
// https://www.geeksforgeeks.org/dsa/inorder-traversal-of-binary-tree/
// https://www.geeksforgeeks.org/dsa/insertion-in-a-binary-tree-in-level-order/
