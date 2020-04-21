include <iostream>
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

int BST::sumNodesRecursive(Node* node) {
    
    if(node == nullptr) {  // Base case for when node DNE.
        return 0; 
        
    } 
    
    return (node->key+sumNodesRecursive(node->left)+sumNodesRecursive(node->right)); // function calling itself

    
}

int BST::sumLeavesRecursive(Node* node) {
    if(node == nullptr) {  // Base case if node DNE 
        return 0;
    } else if(node->left == nullptr && node->right==nullptr) { 
        return node->key; 
    }  
    return sumLeavesRecursive(node->left)+sumLeavesRecursive(node->right); /*  adapted from Geeks for Geeks 
                                                                               "program to count leaf nodes in Bst" */
        
    
}

int BST::sumNodes() {
    if(root == nullptr) {  // case for when otherwise means if node DNE 
        return 0; 
        
    } else { 
        return sumNodesRecursive(root); // call helper function to calculate node sum starting w/ root 
        
    }
}

int BST::sumLeaves() {
    if(root == nullptr) { // case for when otherwise means if node DNE 
        return 0;
        
    } else {
        return sumLeavesRecursive(root); // call helper function to calculate leaves starting w/ root 
        
    }
}

void BST::descendingOrder() {
    if(root == nullptr)
cout<<"Empty tree";
else
descendingOrderRecursive(root);
}

void BST::descendingOrderRecursive(Node* node){ 
    if(node == nullptr) {
    return;
        
    }
    descendingOrderRecursive(node->right); // these are higher in value
      cout<<node->key<<" "; 
    descendingOrderRecursive(node->left); // value lesser than rights value
}


// You can test with following main function:

int main()
{

    BST tree;
    tree.insert(7);
    tree.insert(5);
    tree.insert(13);
    tree.insert(15);
    tree.insert(9);
    tree.insert(3);
    tree.insert(5);
    tree.insert(3);
    tree.insert(4);
    tree.insert(8);
    tree.insert(7);
    tree.insert(9);
    tree.insert(13);
    tree.insert(12);
    tree.insert(11);
    
    cout << endl << "The sum of nodes is " << tree.sumNodes();

    cout << endl << "The sum of leaves is " << tree.sumLeaves();

    cout << endl << "The nodes in Descending Order are ";
    tree.descendingOrder();


     return 0;

}
