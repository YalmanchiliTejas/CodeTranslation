#include <bits/stdc++.h>
using namespace std;

template<typename Type>
struct node_t {
    Type value, sum;
    node_t* child[2]; // left, right
    double priority;
    int size_st;

    node_t(Type val, double pri)
    :   value(val), 
        sum(1),
        priority(pri),
        size_st(1)
    {
        child[0] = child[1] = NULL;
    }
};

template<typename Type>
struct Treap {
private:
    node_t<Type>* root;
    int  size(node_t<Type>* t) {return !t ? 0 : t->size_st;}
    Type sum (node_t<Type>* t) {return !t ? 0 : t->sum    ;}

    // 部分木に関する情報の再計算 (子が変わった時とかに必要)
    node_t<Type>* update(node_t<Type>* t) {
        t->size_st = size(t->child[0]) + size(t->child[1]) + 1       ;
        t->sum     = sum (t->child[0]) + sum (t->child[1]) + t->value;
        return t;
    }

    // t を根とする部分木の回転 (左右どちらも)
    // 新しく根になるノードを返すとあとあと楽
    node_t<Type>* rotate(node_t<Type>* t, int b) {
        node_t<Type>* s = t->child[1 - b];
        t->child[1 - b] = s->child[b];
        s->child[b    ] = t;
        update(t); update(s);
        return s;
    }

    // t が根である木に (val, pri) のノードを挿入
    // k 番目に入れたければ、インデックスを指定可能
    // 根ノードのポインタを返す
    node_t<Type>* insert(node_t<Type>* t, Type val, double pri, int k=-1) {
        if(!t) return new node_t<Type>(val, pri);
        int b, nk;
        if(k >= 0) {
            int c = size(t->child[0]);
            b = (k > c);
            nk = k - (b ? (c+1) : 0);
        }
        else {
            b = (t->value) < val;
            nk = k;
        }

        t->child[b] = insert(t->child[b], val, pri, nk);
        update(t);

        if( (t->priority) < (t->child[b]->priority) ) t = rotate(t, 1-b);
        return t;
    }

    // val が含まれるかどうか
    node_t<Type>* find_node(node_t<Type>* t, Type val) {
        if(!t) return NULL;
        if( (t->value) == val ) return t;

        int c = (t->value) < val;
        return find_node(t->child[c], val);
    }

    // t を根とする部分木に対して、val をキーとするノードを削除
    // 根ノードのポインタを返す
    node_t<Type>* erase(node_t<Type>* t, Type val) {
        if(t == NULL) return NULL;
        if(val < t->value) {
            t->child[0] = erase(t->child[0], val);
        }
        else if(val > t->value) {
            t->child[1] = erase(t->child[1], val);
        }
        else {
            return erase_inside(t, val);
        }
        update(t);
        return t;
    }

    node_t<Type>* erase_inside(node_t<Type>* t, Type val) {
        if(t->child[0] == NULL && t->child[1] == NULL) {
            delete t;
            return NULL;
        }
        else if(t->child[0] == NULL) {
            t = rotate(t, 0);
        }
        else if(t->child[1] == NULL) {
            t = rotate(t, 1);
        }
        else {
            if(t->child[0]->priority > t->child[1]->priority) {
                t = rotate(t, 1);
            }
            else {
                t = rotate(t, 0);
            }
        }
        return erase(t, val);
    }

public:
    Treap()             {root = NULL;      }
    int size()          {return size(root);}
    int sum ()          {return sum (root);}
    void insert(Type val, double pri) {
        // 重複を許さない
        if(find(val)) return;
        root = insert(root, val, pri);
    }
    bool find(Type val) {
        return (find_node(root, val) != NULL);
    }
    void erase(Type val) {
        root = erase(root, val);
    }

    void print_preorder(node_t<Type>* cur) {
        printf(" %lld", cur->value);
        if(cur->child[0] != NULL) print_preorder(cur->child[0]);
        if(cur->child[1] != NULL) print_preorder(cur->child[1]);
    }

    void print_inorder(node_t<Type>* cur) {
        if(cur->child[0] != NULL) print_inorder(cur->child[0]);
        printf(" %lld", cur->value);
        if(cur->child[1] != NULL) print_inorder(cur->child[1]);
    }

    void print() {
        print_inorder(root);
        printf("\n");
        print_preorder(root);
        printf("\n");
    }
};

int main() {
    int Q; cin >> Q;

    Treap<long long int> mp;
    while(Q--) {
        string s; long long int key, pri;
        cin >> s;

        if(s == "insert") {
            cin >> key >> pri;
            mp.insert(key, pri);
        }
        if(s == "find") {
            cin >> key;
            cout << (mp.find(key) ? "yes" : "no") << endl;
        }
        if(s == "delete") {
            cin >> key;
            mp.erase(key);
        }
        if(s == "print") {
            mp.print();
        }
    }
    return 0;
}
