#include <iostream>
#include <vector>

struct node {
    int value, priority;
    node *left = nullptr, *right = nullptr, *parent = nullptr;
    node(int x, int y) {
        value = x;
        priority = y;
    }
};

struct treap {
    node* root = nullptr;
    int size = 0;
    treap() {}
    void insert(int v, int pri) {
        size++;
        node* p = nullptr;
        node* c = root;
        while (c != nullptr) {
            p = c;
            if (v < c->value) {
                c = c->left;
            } else {
                c = c->right;
            }
        }
        if (p == nullptr) {
            root = new node(v, pri);
        } else if (v < p->value) {
            p->left = new node(v, pri);
            p->left->parent = p;
        } else {
            p->right = new node(v, pri);
            p->right->parent = p;
        }
        while (p != nullptr) {
            node* l = p->left;
            node* r = p->right;
            if (l != nullptr && p->priority < l->priority) {
                p = right_rotate(p)->parent;
            } else if (r != nullptr && p->priority < r->priority) {
                p = left_rotate(p)->parent;
            } else {
                break;
            }
        }
        if (p != nullptr && p->parent == nullptr) { root = p; }
    }
    node* right_rotate(node* p) {
        node* c = p->left;
        if (root == p) { root = c; }
        p->left = c->right;
        if (c->right != nullptr) { c->right->parent = p; }
        if (p->parent != nullptr) {
            if (p->parent->left == p) {
                p->parent->left = c;
            } else {
                p->parent->right = c;
            }
        }
        c->right = p;
        c->parent = p->parent;
        p->parent = c;
        return c;
    }
    node* left_rotate(node* p) {
        node* c = p->right;
        if (root == p) { root = c; }
        p->right = c->left;
        if (c->left != nullptr) { c->left->parent = p; }
        if (p->parent != nullptr) {
            if (p->parent->left == p) {
                p->parent->left = c;
            } else {
                p->parent->right = c;
            }
        }
        c->left = p;
        c->parent = p->parent;
        p->parent = c;
        return c;
    }
    node* find(int v) {
        node* x = root;
        while (x != nullptr) {
            if (v < x->value) {
                x = x->left;
            } else if (v > x->value) {
                x = x->right;
            } else {
                return x;
            }
        }
        return nullptr;
    }
    void print_inorder(node* now) {
        if (now->left != nullptr) { print_inorder(now->left); }
        std::cout << " " << now->value;
        if (now->right != nullptr) { print_inorder(now->right); }
    }
    void print_preorder(node* now) {
        std::cout << " " << (*now).value;
        if (now->left != nullptr) { print_preorder(now->left); }
        if (now->right != nullptr) { print_preorder(now->right); }
    }
    void print() {
        if (root != nullptr) { print_inorder(root); }
        std::cout << std::endl;
        if (root != nullptr) { print_preorder(root); }
        std::cout << std::endl;
    }
    void delete_1(node* t, int v) {
        node* l = t->left;
        node* r = t->right;
        if (l == nullptr && r == nullptr) {
            if (root == t) { root = nullptr; }
            if (t->parent != nullptr) {
                if (t->parent->left == t) {
                    t->parent->left = nullptr;
                } else {
                    t->parent->right = nullptr;
                }
            }
            delete t;
        } else if (l == nullptr) {
            delete_2(left_rotate(t), v);
        } else if (r == nullptr) {
            delete_2(right_rotate(t), v);
        } else if (l->priority > r->priority) {
            delete_2(right_rotate(t), v);
        } else {
            delete_2(left_rotate(t), v);
        }
    }
    void delete_2(node* t, int v) {
        if (t == nullptr) {
            ;
        } else if (v < t->value) {
            delete_2(t->left, v);
        } else if (v > t->value) {
            delete_2(t->right, v);
        } else {
            delete_1(t, v);
        }
    }
    void destruct(node* now) {
        if ((*now).left != nullptr) { destruct((*now).left); }
        if ((*now).right != nullptr) { destruct((*now).right); }
        delete now;
    }
    ~treap() {
        if (root != nullptr) { destruct(root); };
    }
};

int main() {
    int n;
    treap tr;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        if (s == "insert") {
            int x, y;
            std::cin >> x >> y;
            tr.insert(x, y);
        } else if (s == "find") {
            int x;
            std::cin >> x;
            if (tr.find(x) == nullptr) {
                std::cout << "no" << std::endl;
            } else {
                std::cout << "yes" << std::endl;
            }
        } else if (s == "delete") {
            int x;
            std::cin >> x;
            tr.delete_2(tr.root, x);
        } else {
            tr.print();
        }
    }
}
