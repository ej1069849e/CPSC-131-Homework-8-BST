#include <iostream>
#include <algorithm>

using namespace std;

struct Node {

    int key;
    Node* left;
    Node* right;

    Node(int element) {

        key = element;
        left = nullptr;
        right = nullptr;

    }

};

class BST {

private:

    Node* root;

    void insertRecursive(Node*, Node*);
    int sumNodesRecursive(Node*);
    int sumLeavesRecursive(Node*);
    void descendingOrderRecursive(Node*);
    
 
public:

    BST();

    void insert(int);
    int sumNodes();
    int sumLeaves();
    void descendingOrder();
    

};

BST::BST() {

    root = nullptr;
}

void BST::insert(int k) {

    Node* node = new Node(k);

    if (root == nullptr)
        root = node;

    else
        insertRecursive(root, node);

}


void BST::insertRecursive(Node* ptr, Node* node)
{

    if (node->key < ptr->key) {

        if (ptr->left == nullptr)
            ptr->left = node;
        else
            insertRecursive(ptr->left, node);
    }
    else
    {

        if (ptr->right == nullptr)
            ptr->right = node;
        else
            insertRecursive(ptr->right, node);
    }
             
}

You can test with following main function:

int main()
{

    BST tree;
    tree.insert(7);
    tree.insert(5);
    tree.insert(13);
    tree.insert(15);
    tree.insert(9);
    tree.insert(3);

    /* Can test on the following as well....

    tree.insert(5);
    tree.insert(3);
    tree.insert(4);
    tree.insert(8);
    tree.insert(7);
    tree.insert(9);
    tree.insert(13);
    tree.insert(12);
    tree.insert(11);
    */
    
    cout << endl << "The sum of nodes is " << tree.sumNodes();

    cout << endl << "The sum of leaves is " << tree.sumLeaves();

    cout << endl << "The nodes in Descending Order are ";
    tree.descendingOrder();


     return 0;

}
