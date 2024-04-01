#ifndef BITREE_H
#define BITREE_H

#include <iostream>
#include <string>

using namespace std;

class BiTreeNode {
public:
    string data;
    BiTreeNode* left;
    BiTreeNode* right;

    BiTreeNode(string value);
};

class BiTree {
private:
    BiTreeNode* root;

    void addHelper(BiTreeNode* node, string value);
    void removeHelper(BiTreeNode*& node, string value);
    BiTreeNode* findMin(BiTreeNode* node);
    void printHelper(BiTreeNode* node);
    void tprintHelper(BiTreeNode* node, int depth);
    void rprintHelper(BiTreeNode* node);

public:
    BiTree();
    void add(string value);
    void remove(string value);
    void print();
    void tprint();
    void rprint();
};

#endif

