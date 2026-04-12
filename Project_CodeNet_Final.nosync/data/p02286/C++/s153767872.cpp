#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int key;
    int priority;
    Node *left;
    Node *right;
};
Node *root, *NIL;

Node* rightRotate(Node *t)
{
    Node *s = t -> left;
    t -> left = s -> right;
    s -> right = t;
    if (root == t) root = s;
    return s;
}

Node* leftRotate(Node *t)
{
    Node *s = t -> right;
    t -> right = s -> left;
    s -> left = t;
    if (root == t) root = s;
    return s;
}

Node* insert(Node *t, int key, int priority)
{
    if (t == NIL)
    {
        t = (Node*)malloc(sizeof(Node));
        t -> key = key;
        t -> priority = priority;
        t -> left = NIL;
        t -> right = NIL;
        return t;
    }
    if (t -> key == key)
    {
        return t;
    }
    if (key < t -> key)
    {
        t -> left = insert(t -> left, key, priority);
        if (t -> priority < t -> left -> priority)
        {
            t = rightRotate(t);
        }
    }
    else
    {
        t -> right = insert(t -> right, key, priority);
        if (t -> priority < t -> right -> priority)
        {
            t = leftRotate(t);
        }
    }
    return t;
}

Node* _delete(Node *t, int key);

Node* deleteNode(Node *t, int key)
{
    if (t == NIL)
    {
        return NIL;
    }
    if (key < t -> key)
    {
        t -> left = deleteNode(t -> left, key);
    }
    else if (key > t -> key)
    {
        t -> right = deleteNode(t -> right, key);
    }
    else
    {
        return _delete(t, key);
    }
    return t;
}

Node* _delete(Node *t, int key)
{
    if (t -> left == NIL && t -> right == NIL)
    {
        return NIL;
    }
    else if (t -> left == NIL)
    {
        t = leftRotate(t);
    }
    else if (t -> right == NIL)
    {
        t = rightRotate(t);
    }
    else
    {
        if (t -> left -> priority > t -> right -> priority)
        {
            t = rightRotate(t);
        }
        else
        {
            t = leftRotate(t);
        }
    }
    return deleteNode(t, key);
}

Node* search(Node* t, int key)
{
    if (t == NIL)
    {
        return NIL;
    }
    if (t -> key > key)
    {
        return search(t -> left, key);
    }
    else if (t -> key < key)
    {
        return search(t -> right, key);
    }
    return t;
}

void inParse(Node *t)
{
    if (t == NIL)
    {
        return;
    }
    inParse(t -> left);
    cout << " " << t -> key;
    inParse(t -> right);
}

void preParse(Node *t)
{
    if (t == NIL)
    {
        return;
    }
    cout << " " << t -> key;
    preParse(t -> left);
    preParse(t -> right);
}

void print(Node *t)
{
    inParse(t);
    cout << endl;
    preParse(t);
    cout << endl;
}

int main()
{
    int m, key, pri;
    string cmd;
    cin >> m;
    for (int i = 0; i != m; ++i)
    {
        cin >> cmd;
        if (cmd == "print")
        {
            print(root);
        }
        else if (cmd == "insert")
        {
            cin >> key >> pri;
            root = insert(root, key, pri);
        }
        else if (cmd == "delete")
        {
            cin >> key;
            deleteNode(root, key);
        }
        else if (cmd == "find")
        {
            cin >> key;
            if (search(root, key) != NIL)
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
    }
    return 0;
}
