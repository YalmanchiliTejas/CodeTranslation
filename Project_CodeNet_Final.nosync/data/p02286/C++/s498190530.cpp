#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 10;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef pair<int, int> P;

void print_line(vector<int> &line) {
    if (line.size() == 0ll) {
        cout << endl;
        return;
    }
    for (ll i = 0; i < line.size(); i++) {
        cout << line[i];
        if (i == line.size() - 1) cout << endl;
        else cout << ' ';
    }
}


typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;
const int mod = 1000000007;

struct Node {
    ll key, priority;
    Node *left, *right, *parent;
};

class Dict {

    Node *begin = NULL;
public:


    Node *find(ll key) {
        Node *x = begin;
        while (x != NULL && key != x->key) {
            if (key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        return x;
    }

    void insert(ll key, ll priority) {
        begin = _insert(begin, key, priority);
    }

    void del(ll key) {
        begin = _del(begin, key);
    }

    void inorder() {
        _inorder(begin);
    }

    void preorder() {
        _preorder(begin);
    }

private:
    void _inorder(Node *node) {
        if (node == NULL) return;
        _inorder(node->left);
        cout << ' ' << node->key;
        _inorder(node->right);
    }

    void _preorder(Node *node) {
        if (node == NULL) return;
        cout << ' ' << node->key;
        _preorder(node->left);
        _preorder(node->right);
    }


    Node *minimum(Node *node) {
        while (node->left != NULL) node = node->left;
        return node;
    }

    Node *right_rotate(Node *t) {
        Node *s = t->left;
        t->left = s->right;
        s->right = t;
        return s;
    }

    Node *left_rotate(Node *t) {
        Node *s = t->right;
        t->right = s->left;
        s->left = t;
        return s;
    }


    Node *_del(Node *t, ll key) {
        if (t == NULL) {
            return NULL;
        }
        if (key < t->key) {
            t->left = _del(t->left, key);
        } else if (key > t->key) {
            t->right = _del(t->right, key);
        } else {
            return _del_rotate(t, key);
        }
        return t;
    }

    Node *_del_rotate(Node *t, ll key) {
        if (t->left == NULL && t->right == NULL) {
            return NULL;
        } else if (t->left == NULL) {
            t = left_rotate(t);
        } else if (t->right == NULL) {
            t = right_rotate(t);
        } else {
            if (t->left->priority > t->right->priority) {
                t = right_rotate(t);
            } else {
                t = left_rotate(t);
            }
        }
        return _del(t, key);
    }

    Node *_insert(Node *t, ll key, ll priority) {
        if (t == NULL) {
            Node *n = new Node();
            n->key = key;
            n->priority = priority;
            return n;
        }
        if (key == t->key) {
            return t;
        }
        if (key < t->key) {
            t->left = _insert(t->left, key, priority);
            if (t->priority < t->left->priority) {
                t = right_rotate(t);
            }
        } else {
            t->right = _insert(t->right, key, priority);
            if (t->priority < t->right->priority) {
                if (t->priority < t->right->priority) {
                    t = left_rotate(t);
                }
            }
        }
        return t;
    }


};

int main() {
    int n;
    cin >> n;

    Dict dict;

    rep(i, n) {
        string command;
        cin >> command;
        if (command == "insert") {
            ll k, p;
            cin >> k >> p;
            dict.insert(k, p);
        } else if (command == "print") {
            dict.inorder();
            cout << endl;
            dict.preorder();
            cout << endl;
        } else if (command == "find") {
            ll k;
            cin >> k;
            if (dict.find(k) == NULL) {
                cout << "no" << endl;
            } else {
                cout << "yes" << endl;
            }
        } else if (command == "delete") {
            ll k;
            cin >> k;
            dict.del(k);
        }
    }
}


