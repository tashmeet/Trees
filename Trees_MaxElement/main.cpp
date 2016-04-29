//
//  main.cpp
//  Trees_MaxElement
//
//  Created by TKC on 4/28/16.
//  Copyright © 2016 Tashmeet Chawla. All rights reserved.
//

#include <iostream>
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
    
    public:
        void Max_Element();
        void insert(int data);
        void SizeOfTree();
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



int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}
