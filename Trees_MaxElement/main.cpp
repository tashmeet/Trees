//
//  main.cpp
//  Trees_MaxElement
//
//  Created by TKC on 4/28/16.
//  Copyright © 2016 Tashmeet Chawla. All rights reserved.
//

#include <iostream>
#include<queue>
#include<stack>
using namespace std;


struct Node{
    int value;
    Node *right;
    Node *left;
};

class Tree
{
        Node* root;
        int Max_ElementRecursive(Node *);
        Node* insert_recursive(int data, Node* node);
        int SizeOfTreeRecursive(Node *);
        void deepestNodeInBinaryTreeRecursive(Node *);
    
    public:
        void Max_Element();
        void insert(int data);
        void SizeOfTree();
        void deepestNodeInBinaryTree();
        int NumberOfBinaryLeaves();
        int FindLevelWithMaxSum(Node* subTree);
        int ifTreesAreStructurallySame(Node* subTree1, Node* subTree2);
        void PrintAllPath(Node* subTree, int path[],int pathLength);
        int add(Node* subTree);
        Node* MirrorOfBinaryTree(Node* subTree);
    int ifTreesAreMirror(Node* subTree1, Node* subTree2);
};

//Max Element in the Tree
void Tree::Max_Element()
{
    if(root == NULL)
        cout<<"Tree is Empty";
    else
    {
        Max_ElementRecursive(root);
    }
}

int Tree::Max_ElementRecursive(Node *subtree)
{
    int max, root_value, left, right;
    max = INT_MIN;
    if(root!= NULL)
    {
        root_value = root->value;
        left = Max_ElementRecursive(root->left);
        right = Max_ElementRecursive(root->right);
        if(left>right)
        {
            max = left;
        }
        else
        {
            max = right;
        }
        if(root_value>max)
            max = root_value;
            
    }
    return max;
}

//Size of Tree
void Tree:: SizeOfTree()
{
    if(root == NULL)
    {
        cout<<"Tree is empty. Size =0";
        return;
    }
    else
    {
        SizeOfTreeRecursive(root);
    }
    
}


int Tree::SizeOfTreeRecursive(Node* subtree)
{
    return (SizeOfTreeRecursive(root->left)+1+SizeOfTreeRecursive(root->right));
}

//Insert
Node* Tree::insert_recursive(int data, Node* node)
{
    if(node ==NULL)
    {
        Node* temp;
        temp = new Node();
        temp->value = data;
        temp->right = temp->left = NULL;
        return temp;
    }
    else if(data <=node->value)
    {
        node->left =insert_recursive(data, node->left);
    }
    else
    {
        node->right=insert_recursive(data, node->right);
    }
    
    return node;
}


void Tree::insert(int data)
{
    root = insert_recursive(data, root);
}

//Deepest Node in Binary Tree
void Tree::deepestNodeInBinaryTree()
{
    if(root == NULL)
    {
        return;
    }
    deepestNodeInBinaryTreeRecursive(root);
}


void Tree::deepestNodeInBinaryTreeRecursive(Node *subTree)
{
    queue<Node*> Q;
    Node* current;
    Q.push(root);
    while(!Q.empty())
    {
        current = Q.front();
        Q.pop();
        if(current->left)
            Q.push(current->left);
        if(current->right)
            Q.push(current->right);
        
    }
    cout<<"Deepest node in the tree is:"<<current;
}


//Find the number of leaves in binary tree.

int Tree:: NumberOfBinaryLeaves()
{
    Node* current;
    queue<Node*> Q;
    int count=0;
    if(root==NULL)
        return 0;
    Q.push(root);
    while(!Q.empty())
    {
        current = Q.front();
        Q.pop();
        if(!current->left && !current->right)
            count++;
        else
        {
            if(current->left)
                Q.push(current->left);
            if(current->right)
                Q.push(current->right);
        }
    }
    return count;
    
}

//Given two binary trees return true if they are structurally identical

int Tree::ifTreesAreStructurallySame(Node* subTree1, Node* subTree2)
{
    if((subTree1==NULL) && (subTree2==NULL))
        return 1;
    if((subTree1 == NULL) || (subTree2 ==NULL))
        return 0;
    return (subTree1->value == subTree2->value && ifTreesAreStructurallySame(subTree1->left, subTree2->left) && ifTreesAreStructurallySame(subTree1->right, subTree2->right));
}



//Finding the level which is having maximum sum in the binary tree

int Tree::FindLevelWithMaxSum(Node* subTree)
{
    Node* temp;
    int level =0, maxLevel =0;
    queue<Node*> Q;
    int currentSum=0,maxSum =0;
    if(!root)
        return 0;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty())
    {
        temp = Q.front();
        Q.pop();
        if(temp == NULL)
        {
            if(currentSum>maxSum)
            {
                maxSum = currentSum;
                maxLevel = level;
            }
            currentSum=0;
            if(!Q.empty())
            {
                Q.push(NULL);
            }
            level++;
        }
        else
        {
            currentSum+= temp ->value;
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
        }
    }
    return maxLevel;
    
}


//Print all root to leaf path.

void Tree::PrintAllPath(Node* subTree, int path[],int pathLength)
{
    if(root == NULL)
        return;
    
    path[pathLength] = subTree->value;
    pathLength++;
    
    if(subTree->left == NULL && subTree->right== NULL)
    {
        for(int i=0;i<pathLength;i++)
        {
            cout<<path[i];
        }
    }
    else
    {
        PrintAllPath(subTree->left, path, pathLength);
        PrintAllPath(subTree->right, path, pathLength);
    }
    
}


//Given a sum whether there exist a path from root to any of the nodes.

int HasPathSum(Node* subTree, int sum)
{
    if(subTree == NULL)
    {
        return 0;
    }
    else
    {
        int remainingSum = sum-subTree->value;
        if((subTree->left && subTree->right)||())
        
        
    }
    
    
    
}




//Find the sum of all elements in binary tree

int Tree::add(Node* subTree)
{
    if(root == NULL)
        return 0;
    else
        return (subTree->value + add(subTree->left)+add(subTree->right));
}


//Convert a tree to its Mirror Tree. Mirror of a tree is another tree with left and right children of all non-leaf nodes interchanged.

Node* Tree::MirrorOfBinaryTree(Node* subTree)
{
    Node* temp;
    if(subTree)
    {
        MirrorOfBinaryTree(subTree->left);
        MirrorOfBinaryTree(subTree->right);
        
        temp= subTree->left;
        subTree->left=subTree->right;
        subTree->right = temp;
    }
    return subTree;
}


//Given 2 trees, check whether they are mirrors of each other.

int Tree::ifTreesAreMirror(Node* subTree1, Node* subTree2)
{
    if(subTree1==NULL && subTree2==NULL)
        return 1;
    if(subTree1==NULL || subTree2==NULL)
        return 0;
    if(subTree1->value != subTree2->value)
        return 0;
    else
        return(ifTreesAreMirror(subTree1->left, subTree2->right) && ifTreesAreMirror(subTree1->right, subTree2->left));
}


//Construct a binary tree from given inorder and preorder traversals
//Inorder- DBEAFC
//PreOrder- ABDECF

Node* BuildBinaryTree(int inOrder[], int preOrder[], int inStart, int inEnd)
{
    
}

//Traverse a binary tree in Zigzag Order.




int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}
