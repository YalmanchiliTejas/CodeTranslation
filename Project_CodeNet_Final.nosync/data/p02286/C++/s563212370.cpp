#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int key, priority;
    Node *left, *right;
    Node(int key, int priority)
    {
        this->key = key;
        this->priority = priority;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *leftRotate(Node *t)
{
    Node *s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}

Node *rightRotate(Node *t)
{
    Node *s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}

Node *insert(Node *t, int key, int priority)
{
    if (t == NULL)
        return new Node(key, priority);
    if (key == t->key)
        return t;
    if (key < t->key)
    {
        t->left = insert(t->left, key, priority);
        if (t->priority < t->left->priority)
            t = rightRotate(t);
    }
    else
    {
        t->right = insert(t->right, key, priority);
        if (t->priority < t->right->priority)
            t = leftRotate(t);
    }
    return t;
}

Node *deletHelper(Node *, int);

Node *delet(Node *t, int key)
{
    if (t == NULL)
        return NULL;
    if (key < t->key)
        t->left = delet(t->left, key);
    else if (key > t->key)
        t->right = delet(t->right, key);
    else
        return deletHelper(t, key);
    return t;
}

Node *deletHelper(Node *t, int key)
{
    if (t->left == NULL && t->right == NULL)
    {
        delete t;
        return NULL;
    }
    else if (t->left == NULL)
        t = leftRotate(t);
    else if (t->right == NULL)
        t = rightRotate(t);
    else
    {
        if (t->left->priority > t->right->priority)
            t = rightRotate(t);
        else
            t = leftRotate(t);
    }
    return delet(t, key);
}

void find(Node *t, int key)
{
    if (t == NULL)
    {
        cout << "no" << endl;
        return;
    }
    else if (key == t->key)
    {
        cout << "yes" << endl;
        return;
    }
    else if (key < t->key)
        find(t->left, key);
    else
        find(t->right, key);
    return;
}

void printInorder(Node *t)
{
    if (t == NULL)
        return;
    printInorder(t->left);
    cout << ' ' << t->key;
    printInorder(t->right);
    return;
}

void printPreorder(Node *t)
{
    if (t == NULL)
        return;
    cout << ' ' << t->key;
    printPreorder(t->left);
    printPreorder(t->right);
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        string operation;
        cin >> operation;
        if (operation == "insert")
        {
            int k, p;
            cin >> k >> p;
            root = insert(root, k, p);
        }
        else if (operation == "find")
        {
            int k;
            cin >> k;
            find(root, k);
        }
        else if (operation == "delete")
        {
            int k;
            cin >> k;
            root = delet(root, k);
        }
        else
        {
            printInorder(root);
            cout << endl;
            printPreorder(root);
            cout << endl;
        }
    }
    return 0;
}

