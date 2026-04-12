#include <iostream>
#include <string>
#include <set>

using namespace std;

class Node {
public:
    Node(int key, int priority) 
        : key_(key), priority_(priority), leftChild_(nullptr), rightChild_(nullptr) {}

    static Node* rightRotate(Node* t) {
        Node* s = t->leftChild_;
        t->leftChild_ = s->rightChild_;
        s->rightChild_ = t;
        return s;
    }
    static Node* leftRotate(Node* t) {
        Node* s = t->rightChild_;
        t->rightChild_ = s->leftChild_;
        s->leftChild_ = t;
        return s;
    }
    static Node* insert(Node* t, int key, int priority) {
        if (t == nullptr) {
            return new Node(key, priority); // 葉に到達したら新しい節点を生成して返す
        }
        if (key == t->key_) {
            return t;   // 重複したkeyは無視
        }
        if (key < t->key_) {    // 左の子へ移動
            t->leftChild_ = insert(t->leftChild_, key, priority);   // 左の子へのポインタを更新
            if (t->priority_ < t->leftChild_->priority_) {  // 左の子の方が優先度が高い場合右回転
                t = rightRotate(t);
            }
        }
        else {  // 右の子へ移動
            t->rightChild_ = insert(t->rightChild_, key, priority); // 右の子へのポインタを更新
            if (t->priority_ < t->rightChild_->priority_) { // 右の子の方が優先度が高い場合左回転
                t = leftRotate(t);
            }
        }
        return t;
    }
    static Node* erase_(Node* t, int key) { // 葉の場合
        if ((t->leftChild_ == nullptr) && (t->rightChild_ == nullptr)) {
            return nullptr;
        }
        else if (t->leftChild_ == nullptr) {    // 右の子のみを持つ場合左回転
            t = leftRotate(t);
        }
        else if (t->rightChild_ == nullptr) {   // 左の子のみを持つ場合右回転
            t = rightRotate(t);
        }
        else {  // 左の子と右の子を両方持つ場合
            if (t->leftChild_->priority_ > t->rightChild_->priority_) {
                t = rightRotate(t);
            }
            else {
                t = leftRotate(t);
            }
        }
        return erase(t, key);
    }
    static Node* erase(Node* t, int key) {
        if (t == nullptr) {
            return nullptr;
        }
        if (key < t->key_) {
            t->leftChild_ = erase(t->leftChild_, key);
        }
        else if (key > t->key_) {
            t->rightChild_ = erase(t->rightChild_, key);
        }
        else {
            return erase_(t, key);
        }
        return t;
    }
    bool find(int key) {
        Node* x = this;
        while (x != nullptr) {
            if (key == x->key_) {
                return true;
            }
            else if (key < x->key_) {
                x = x->leftChild_;  // 左の子へ移動
            }
            else {
                x = x->rightChild_; // 右の子へ移動
            }
        }
        return false;
    }
    void printInorder() {
        if (leftChild_ != nullptr) {
            leftChild_->printInorder();
        }
        cout << " " << key_;
        if (rightChild_ != nullptr) {
            rightChild_->printInorder();
        }
    }
    void printPreorder() {
        cout << " " << key_;
        if (leftChild_ != nullptr) {
            leftChild_->printPreorder();
        }
        if (rightChild_ != nullptr) {
            rightChild_->printPreorder();
        }
    }
private:
    int key_;
    int priority_;
    Node* leftChild_;
    Node* rightChild_;
};

class Tree {
public:
    Tree() : root_(nullptr) {}
    void insert(int key, int priority) {
        root_ = Node::insert(root_, key, priority);
    }
    bool find(int key) {
        if (root_ == nullptr) {
            return false;
        }
        return root_->find(key);
    }
    void erase(int key) {
        root_ = Node::erase(root_, key);
    }
    void print() {
        if (root_ == nullptr) {
            return;
        }
        root_->printInorder();
        cout << endl;
        root_->printPreorder();
        cout << endl;
    }
private:
    Node* root_;
};

int main()
{
    int n;
    cin >> n;
    string operation;
    Tree tree;
    for (int i = 0; i < n; ++i) {
        cin >> operation;
        if (operation == "insert") {
            int k, p;
            cin >> k >> p;
            tree.insert(k, p);
        }
        else if (operation == "find") {
            int k;
            cin >> k;
            if (tree.find(k)) {
                cout << "yes" << endl;
            }
            else {
                cout << "no" << endl;
            }
        }
        else if (operation == "delete") {
            int k;
            cin >> k;
            tree.erase(k);
        }
        else {
            tree.print();
        }

    }
}

