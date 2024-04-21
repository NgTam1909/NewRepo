#include<stdio.h>
#include <stdlib.h>

typedef int data;

typedef struct node {
	data infor;
	node* left;
	node* right;
}Node;

typedef Node* binaryTree;

//khoi tao 1 cay khung nhi phan
void initTree(binaryTree* T) {
	*T = NULL;
}

//kiem tra cay khung rong
int emptyTree(binaryTree T) {
	return T == NULL;
}

//xac dinh con trai
binaryTree leftTree(binaryTree T) {
	if (T != NULL)
		return T->left;
	else
		return NULL;
}

//xac dinh con phai
binaryTree rightTree(binaryTree T) {
	if (T != NULL)
		return T->right;
	else
		return NULL;
}

//kiem tra lá
bool isLear(binaryTree T) {
	if (T != NULL)
		return (leftTree(T) == NULL) && (rightTree(T) == NULL);
	else
		return false;
}

//tong cac node trong cay nhi phan
int sumNode(binaryTree T) {
	if (!emptyTree(T))
		return (1 + sumNode(leftTree(T)) + sumNode(rightTree(T)));
	else return 0;
}

//them 1 node trong cay nhi phan
Node *creatNode(data x) {
	Node* a = (Node*)malloc(sizeof(Node));
	a->infor = x;
	a->left = NULL;
	a->right = NULL;
	return a;
}

//Nhap vao 1 cay khung nhi phan 
void input(binaryTree &T) {
	int x;
	//neu X=0 lá khong co phan tu
	printf("\n\t\t\t(X=0 neu cay rong)\nNhap X: ");
	scanf("%d", &x);
	if (x != 0)
	{
		T = creatNode(x);
		printf("\nNhap con trai: %d", T->infor);
		input(T->left);
		printf("\nNhap con phai: %d", T->infor);
		input(T->right);
	}
	else 
		x = NULL;
}

//duyet cay truoc
void preOrder(binaryTree T){
	if(T != NULL){
		printf("%5d", T->infor);
		preOrder(T->left);
		preOrder(T->right);
	}
}

//duyet cay giua
void inOder(binaryTree T){
	if(T != NULL){
		inOder(T->left);
		printf("%5d", T->infor);
		inOder(T->right);
	}
}

//duyet cay sau
void postOder(binaryTree T){
	if(T != NULL){
		postOder(T->left);
		postOder(T->right);
		printf("%5d", T->infor);
	}
}

//chieu cao cua cay khung nhi phan
int height(binaryTree T){
	if(T==NULL)
		return 0;
	int leftHeight = height(T->left);
	int rightHeight = height(T->right);
	if (leftHeight > rightHeight)
		return leftHeight + 1;
	else
		return rightHeight + 1;
//	printf("\n\tleftHeight = %d, rightHeight = %d\n", leftHeight, rightHeight);
}

//tim con trai cua 1 node tren cay 
binaryTree LeftChild(binaryTree &T, data x) {
	Node* leftChild = NULL;
	if (T == NULL)
		return NULL;
	if (T->infor == x)
		return T->left;
	leftChild = LeftChild(T->left, x);
	if (leftChild != NULL)
		return leftChild;
}

void FindLeftChild(binaryTree T) {
	data x;
	printf("\n\nNhap nut: ");
	scanf("%d", &x);
	Node* leftChild = LeftChild(T, x);
	if (leftChild != NULL)
		printf("Nut con trai cua nut %d la: %d", x, leftChild->infor);
	else
		printf("Nut %d khong co nut con trai!!!", x);
}

//tim con phai cau 1 node tren cay
binaryTree RightChild(binaryTree &T, data x) {
	Node *rightChild = NULL;
	if (T == NULL)
		return NULL;
	if (T->infor == x)
		return T->right;
	rightChild = RightChild(T->right,x);
	if (rightChild != NULL)
		return rightChild;
}

void FindRightChild(binaryTree T) {
	data x;
	printf("\n\nNhap nut: ");
	scanf("%d", &x);
	Node* rightChild = RightChild(T, x);
	if (rightChild != NULL)
		printf("Nut con phai cua nut %d la: %d", x, rightChild->infor);
	else
		printf("Nut %d khong co nut con phai!!!", x);
}

/*
binaryTree parent(binaryTree T, binaryTree child) {
	if (T == NULL || T == child)
		return NULL;
	if (T->left == child || T->right == child)
		return T;
	binaryTree left = parent(T->left, child);
	if (left != NULL)
		return left;
	return parent(T->right, child);
}
*/

binaryTree papa(binaryTree root, data x) {
	if (root->infor = x)
		return NULL;
	if ((root->infor != NULL && root->right->infor == x) || (root->infor != NULL && root->left->infor == x))
		return root;
	binaryTree leftpapa = papa(root->left, x);
	if (leftpapa != NULL)
		return leftpapa;
	else
		return papa(root->right, x);
}

void FindPaPa(binaryTree T) {
	data x;
	printf("\n\nNhap nut: ");
	scanf("%d", &x);
	binaryTree PaPaNode = papa(T,x);
	if (PaPaNode != NULL)
		printf("Cha cua nut %d la %d\n", x, PaPaNode->infor);
	else
		printf("Khong tim thay cha cua nut %d\n", x);
}









