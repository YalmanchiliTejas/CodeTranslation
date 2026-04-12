#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

template <typename T>
struct Node
{
    T val;
    T sum; // sum of subtree's values
    Node<T> *left;
    Node<T> *right;
    double pri;
    int cnt; // size of subtree

    Node(T v, double p) : val(v), pri(p), cnt(1), sum(v)
    {
        left = right = NULL;
    }
};

template <typename T>
class Treap
{
    Node<T> *root;
    int count(Node<T> *t) { return !t ? 0 : t->cnt; }
    T sum(Node<T> *t) { return !t ? 0 : t->sum; }

    Node<T> *update(Node<T> *t)
    {
        t->cnt = count(t->left) + count(t->right) + 1;
        t->sum = sum(t->left) + sum(t->right) + t->val;
        return t;
    }

    Node<T> *rightRotate(Node<T> *t)
    {
        Node<T> *s = t->left;
        t->left = s->right;
        s->right = t;
        update(s);
        update(t);
        return s;
    }

    Node<T> *leftRotate(Node<T> *t)
    {
        Node<T> *s = t->right;
        t->right = s->left;
        s->left = t;
        update(s);
        update(t);
        return s;
    }

    Node<T> *find(Node<T> *t, T v)
    {
        if (!t)
            return NULL;
        if (t->val == v)
            return t;
        if (t->val > v)
            return find(t->left, v);
        else
            return find(t->right, v);
    }

    Node<T> *merge(Node<T> *l, Node<T> *r)
    {
        if (!l || !r)
            return l ? l : r;

        if (l->pri > r->pri)
        {
            l->right = merge(l->right, r);
            return update(l);
        }
        else
        {
            r->left = merge(l, r->left);
            return update(r);
        }
    }

    // [0,k), [k,n)
    pair<Node<T> *, Node<T> *> split(Node<T> *t, int k)
    {
        if (!t)
            return make_pair(NULL, NULL);

        if (k <= count(t->left))
        {
            pair<Node<T> *, Node<T> *> s = split(t->left, k);
            t->left = s.second;
            return pair<Node<T> *, Node<T> *>(s.first, update(t));
        }
        else
        {
            pair<Node<T> *, Node<T> *> s = split(t->right, k - count(t->left) - 1);
            t->right = s.first;
            return pair<Node<T> *, Node<T> *>(update(t), s.second);
        }
    }

    // 木 t に (v, p) ノードを挿入
    // 挿入位置を k で指定可能
    Node<T> *insert(Node<T> *t, T v, double p, int k = -1)
    {
        if (!t)
        {
            return t = new Node<T>(v, p);
        }
        if (t->val == v)
        {
            return t;
        }
        if (v < t->val)
        {
            t->left = insert(t->left, v, p);
            if (t->pri < t->left->pri)
            {
                t = rightRotate(t);
            }
        }
        else
        {
            t->right = insert(t->right, v, p);
            if (t->pri < t->right->pri)
            {
                t = leftRotate(t);
            }
        }
        update(t);
        return t;
    }

    Node<T> *erase(Node<T> *t, T v)
    {
        if (t == NULL)
        {
            return NULL;
        }
        if (v < t->val)
        {
            t->left = erase(t->left, v);
        }
        else if (v > t->val)
        {
            t->right = erase(t->right, v);
        }
        else
        {
            return _erase(t, v);
        }
        update(t);
        return t;
    }

    Node<T> *_erase(Node<T> *t, T v)
    {
        if (t->left == NULL && t->right == NULL)
        {
            return NULL;
        }
        else if (t->left == NULL)
        {
            t = leftRotate(t);
        }
        else if (t->right == NULL)
        {
            t = rightRotate(t);
        }
        else
        {
            if (t->left->pri > t->right->pri)
            {
                t = rightRotate(t);
            }
            else
            {
                t = leftRotate(t);
            }
        }
        update(t);
        return erase(t, v);
    }

  public:
    Treap() { root = NULL; }
    T count() { return count(root); }
    T sum() { return sum(root); }
    void insert(T v, double p)
    {
        root = insert(root, v, p);
    }
    bool find(T v)
    {
        return find(root, v);
    }
    void erase(T v)
    {
        root = erase(root, v);
    }
    void preorder(Node<T> *cur)
    {
        if (cur == NULL)
            return;
        cout << " " << cur->val;
        preorder(cur->left);
        preorder(cur->right);
    }
    void inorder(Node<T> *cur)
    {
        if (cur == NULL)
            return;
        inorder(cur->left);
        cout << " " << cur->val;
        inorder(cur->right);
    }
    void print()
    {
        inorder(root);
        cout << endl;
        preorder(root);
        cout << endl;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;
    Treap<ll> tr;
    while (Q--)
    {
        string s;
        cin >> s;
        if (s == "insert")
        {
            ll key;
            double p;
            cin >> key >> p;
            tr.insert(key, p);
        }
        else if (s == "find")
        {
            ll key;
            cin >> key;
            cout << (tr.find(key) ? "yes" : "no") << endl;
        }
        else if (s == "delete")
        {
            ll key;
            cin >> key;
            tr.erase(key);
        }
        else
        {
            tr.print();
        }
    }
}

