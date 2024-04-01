#include "BiTree.h"
#include <iostream>
#include <string>

using namespace std;

class BiTreeNode {
public:
    string data;
    BiTreeNode* left;
    BiTreeNode* right;

    BiTreeNode(string value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BiTree {
private:
    BiTreeNode* root;

    void addHelper(BiTreeNode* node, string value) {
        if (value < node->data) {
            if (node->left == nullptr) {
                node->left = new BiTreeNode(value);
            }
            else {
                addHelper(node->left, value);
            }
        }
        else {
            if (node->right == nullptr) {
                node->right = new BiTreeNode(value);
            }
            else {
                addHelper(node->right, value);
            }
        }
    }

    void removeHelper(BiTreeNode*& node, string value) {
        if (node == nullptr) {
            return;
        }

        if (value < node->data) {
            removeHelper(node->left, value);
        }
        else if (value > node->data) {
            removeHelper(node->right, value);
        }
        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            }
            else if (node->left == nullptr) {
                BiTreeNode* temp = node;
                node = node->right;
                delete temp;
            }
            else if (node->right == nullptr) {
                BiTreeNode* temp = node;
                node = node->left;
                delete temp;
            }
            else {
                BiTreeNode* temp = findMin(node->right);
                node->data = temp->data;
                removeHelper(node->right, temp->data);
            }
        }
    }

    BiTreeNode* findMin(BiTreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void printHelper(BiTreeNode* node) {
        if (node != nullptr) {
            printHelper(node->left);
            cout << node->data << " ";
            printHelper(node->right);
        }
    }

    void tprintHelper(BiTreeNode* node, int depth) {
        if (node != nullptr) {
            tprintHelper(node->right, depth + 1);
            for (int i = 0; i < depth; ++i) {
                cout << "  ";
            }
            cout << node->data << endl;
            tprintHelper(node->left, depth + 1);
        }
    }

    void rprintHelper(BiTreeNode* node) {
        if (node != nullptr) {
            rprintHelper(node->right);
            cout << node->data << " ";
            rprintHelper(node->left);
        }
    }

public:
    BiTree() {
        root = nullptr;
    }

    void add(string value) {
        if (root == nullptr) {
            root = new BiTreeNode(value);
        }
        else {
            addHelper(root, value);
        }
    }

    void remove(string value) {
        removeHelper(root, value);
    }

    void print() {
        printHelper(root);
        cout << endl;
    }

    void tprint() {
        tprintHelper(root, 0);
    }

    void rprint() {
        rprintHelper(root);
        cout << endl;
    }
};

int main() {
    BiTree tree;

    tree.add("google.com");
    tree.add("apple.com");
    tree.add("stackoverflow.com");
    tree.add("amazon.com");
    tree.add("github.com");

    cout << "In alphabetical order:" << endl;
    tree.print();

    cout << "\nIn tree format:" << endl;
    tree.tprint();

    cout << "\nIn reverse alphabetical order:" << endl;
    tree.rprint();

    return 0;
}
