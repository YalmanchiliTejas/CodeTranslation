#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int key, priority;
    struct Node *left, *right;
} Node;

class Treap
{
private:
    Node *root;

    void setNode(Node *node, int key, int priority, Node *left, Node *right)
    {
        node->key = key;
        node->priority = priority;
        node->left = left;
        node->right = right;
    };

    Node *allocNode()
    {
        return (Node *)malloc(sizeof(Node));
    };

    Node *allocNode(int key, int priority, Node *left, Node *right)
    {
        Node *node = allocNode();
        setNode(node, key, priority, left, right);
        return node;
    };

    void preorder(Node *node)
    {
        if (node == NULL)
            return;
        printf(" %d", node->key);
        preorder(node->left);
        preorder(node->right);
    };

    void inorder(Node *node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        printf(" %d", node->key);
        inorder(node->right);
    };

    bool findNode(int key, Node *node)
    {
        if (node == NULL)
            return false;
        if (key == node->key)
            return true;
        if (key < node->key)
            return findNode(key, node->left);
        return findNode(key, node->right);
    }

    Node *rightRotate(Node *node)
    {
        Node *tmp = node->left;
        node->left = tmp->right;
        tmp->right = node;
        return tmp;
    };

    Node *leftRotate(Node *node)
    {
        Node *tmp = node->right;
        node->right = tmp->left;
        tmp->left = node;
        return tmp;
    };

    Node *insertNode(Node *node, int key, int priority)
    {
        if (node == NULL)
            return allocNode(key, priority, NULL, NULL);
        if (key == node->key)
            return node;
        if (key < node->key)
        {
            node->left = insertNode(node->left, key, priority);
            if (node->priority < node->left->priority)
                node = rightRotate(node);
        }
        else
        {
            node->right = insertNode(node->right, key, priority);
            if (node->priority < node->right->priority)
                node = leftRotate(node);
        }
        return node;
    };

    Node *deleteNode(Node *node, int key)
    {
        if (node->left == NULL && node->right == NULL)
            return NULL;
        else if (node->left == NULL)
            node = leftRotate(node);
        else if (node->right == NULL)
            node = rightRotate(node);
        else
        {
            if (node->left->priority > node->right->priority)
                node = rightRotate(node);
            else
                node = leftRotate(node);
        }
        return _deleteNode(node, key);
    }

    Node *_deleteNode(Node *node, int key)
    {
        if (node == NULL)
            return NULL;
        if (key < node->key)
            node->left = _deleteNode(node->left, key);
        else if (key > node->key)
            node->right = _deleteNode(node->right, key);
        else
            return deleteNode(node, key);
        return node;
    }

public:
    Treap()
    {
        root = NULL;
    };

    void insert(int key, int priority)
    {
        root = insertNode(root, key, priority);
    };

    void printPreorder()
    {
        preorder(root);
    };

    void printInorder()
    {
        inorder(root);
    };

    bool find(int key)
    {
        if (findNode(key, root))
        {
            cout << "yes" << endl;
            return true;
        }

        cout << "no" << endl;
        return false;
    };

    void deleteKey(int key)
    {
        root = _deleteNode(root, key);
    };
};

int main()
{
    int n;
    Treap tree;
    cin >> n;
    string s;
    while (n--)
    {
        cin >> s;
        if (s == "insert")
        {
            int a, b;
            cin >> a >> b;
            tree.insert(a, b);
        }
        else if (s == "find")
        {
            int a;
            cin >> a;
            tree.find(a);
        }
        else if (s == "delete")
        {
            int a;
            cin >> a;
            tree.deleteKey(a);
        }
        else if (s == "print")
        {
            tree.printInorder();
            cout << endl;
            tree.printPreorder();
            cout << endl;
        }
    }
}
