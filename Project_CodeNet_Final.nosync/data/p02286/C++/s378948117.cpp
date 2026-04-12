#define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <clocale>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i, s, n) for(int i = (s), i##_len=(n); i < i##_len; ++i)
#define FORS(i, s, n) for(int i = (s), i##_len=(n); i <= i##_len; ++i)
#define VFOR(i, s, n) for(int i = (s); i < (n); ++i)
#define VFORS(i, s, n) for(int i = (s); i <= (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define REPS(i, n) FORS(i, 0, n)
#define VREP(i, n) VFOR(i, 0, n)
#define VREPS(i, n) VFORS(i, 0, n)
#define RFOR(i, s, n) for(int i = (s), i##_len=(n); i >= i##_len; --i)
#define RFORS(i, s, n) for(int i = (s), i##_len=(n); i > i##_len; --i)
#define RREP(i, n) RFOR(i, n, 0)
#define RREPS(i, n) RFORS(i, n, 0)
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(ALL(v), greater<decltype(v[0])>())
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())

using ll = long long;
using Pi_i = pair<int, int>;
using VB = vector<bool>;
using VC = vector<char>;
using VD = vector<double>;
using VI = vector<int>;
using VLL = vector<ll>;
using VS = vector<string>;
using VSH = vector<short>;

const int MOD = 1000000007;
const int INF = 1000000000;
const int NIL = -1;

template<class T>
bool chmax(T &a, const T &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T>
bool chmin(T &a, const T &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}




class BinarySearchTree{
    struct Node{
        int key, priority;
        Node *right, *left;
        Node(): key(NIL), priority(NIL), right(nullptr), left(nullptr){};
        Node(int k, int p): key(k), priority(p), right(nullptr),  left(nullptr){};
    };
    Node *root, *NILL = nullptr;
public:
    BinarySearchTree(): root(nullptr){};
private:
    Node* rightRotate(Node* v){
        Node* u = v->left;
        if(v == root){
            v->left = u->right;
            u->right = v;
            root = u;
        }else{
            v->left = u->right;
            u->right = v;
        }
        return u;
    }

    Node* leftRotate(Node* v){
        Node* u = v->right;
        if(v == root){
            v->right = u->left;
            u->left = v;
            root = u;
        }else{
            v->right = u->left;
            u->left = v;
        }
        return u;
    }

    Node* insert(Node *v, int k, int p){
        if(v == nullptr){
            if(v == root){
                v = new Node;
                v->key = k; v->priority = p;
                v->left = v->right = nullptr;
                root = v;
            }else{
                v = new Node;
                v->key = k; v->priority = p;
                v->left = v->right = nullptr;
            }
            return v;
        }
        if(k == v->key)
            return v;
        if(k < v->key){
            v->left = insert(v->left, k, p);
            if(v->priority < v->left->priority)
                v = rightRotate(v);
        }else{
            v->right = insert(v->right, k, p);
            if(v->priority < v->right->priority)
                v = leftRotate(v);
        }
        return v;
    }

    Node* find(Node *v, int k){
        while(v != nullptr && k != v->key){
            if(k < v->key) v = v->left;
            else v = v->right;
        }
        return v;
    }

    Node* tDelete(Node *v, int k){
        if(v == nullptr)
            return nullptr;
        if(k < v->key)
            v->left = tDelete(v->left, k);
        else if(k > v->key)
            v->right = tDelete(v->right, k);
        else{
            if(v->left == nullptr && v->right == nullptr){
                // delete(v);
                v = nullptr;
                return nullptr;
            }
            else if(v->left == nullptr)
                v = leftRotate(v);
            else if(v->right == nullptr)
                v = rightRotate(v);
            else{
                if(v->left->priority > v->right->priority)
                    v = rightRotate(v);
                else v = leftRotate(v);
            }
            return tDelete(v, k);
        }
        return v;
    }

    void inOrder(Node *v){
        if(v == nullptr) return;
        inOrder(v->left);
        cout << " " << v->key;
        inOrder(v->right);
    }

    void preOrder(Node *v){
        if(v == nullptr) return;
        cout << " " << v->key;
        preOrder(v->left);
        preOrder(v->right);
    }
public:
    void insert(int k, int p){
        insert(root, k, p);
    }

    bool find(int x){
        Node *t = find(root, x);
        return t != nullptr;
    }

    void tDelete(int x){
        if(!find(x)) return;
        tDelete(root, x);
    }

    void outInOrder(){
        inOrder(root);
    }

    void outPreOrder(){
        preOrder(root);
    }
};


int main(){
    int n; cin >> n;
    BinarySearchTree T;
    REP(i, n){
        int x, p;
        string com; cin >> com;
        if(com == "insert"){
            cin >> x >> p;
            T.insert(x, p);
        }
        else if(com == "find"){
            cin >> x;
            cout << (T.find(x) ? "yes" : "no") << endl;
        }
        else if(com == "delete"){
            cin >> x;
            T.tDelete(x);
        }
        else{
            T.outInOrder();
            cout << "\n";
            T.outPreOrder();
            cout << "\n";
        }
    }
    return 0;
}

