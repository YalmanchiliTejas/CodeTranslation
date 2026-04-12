// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>
#include <list>
#include <random>

// macros
#define ll long long int
#define pb emplace_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1e9 + 7;

// solve
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}

template <typename T>
struct Treap{
  random_device rnd;
  struct Node{
    T key;
    int pri;
    Node *l, *r;
    Node(T key, int pri): key(key), pri(pri), l(nullptr), r(nullptr){}
    ~Node(){
      delete l;
      delete r;
    }
  };
  using Tree = Node *;
  Tree root = nullptr;
  size_t _size = 0;

  Treap(){}
  size_t size(){
    return _size;
  }
  void split(Tree t, T key, Tree &l, Tree &r){
    if(!t){
      l = r = nullptr;
    }else if(key < t->key){
      split(t->l, key, l, t->l);
      r = t;
    }else{
      split(t->r, key, t->r, r);
      l = t;
    }
  }
  void merge(Tree &t, Tree l, Tree r){
    if(!l || !r){
      if(!l)t = r;
      if(!r)t = l;
      return;
    }
    if(l->pri > r->pri){
      merge(l->r, l->r, r);
      t = l;
    }else{
      merge(r->l, l, r->l);
      t = r;
    }
  }
  void insert(Tree &t, Tree n){
    if(!t)t = n;
    else if(n->pri > t->pri){
      split(t, n->key, n->l, n->r);
      t = n;
    }else{
      if(n->key < t->key)insert(t->l, n);
      else insert(t->r, n);
    }
  }
  void insert(T key){
    insert(root, new Node(key, rnd()));
    _size++;
  }
  void insert(T key, T pri){
    insert(root, new Node(key, pri));
    _size++;
  }
  void erase(Tree &t, T key){
    if(t->key == key){
      merge(t, t->l, t->r);
      _size--;
    }else{
      if(key < t->key)erase(t->l, key);
      else erase(t->r, key);
    }
  }
  void erase(T key){
    erase(root, key);
  }
  bool find(Tree &t, T key){
    if(!t)return false;
    else if(t->key == key)return true;
    else{
      if(key < t->key)return find(t->l, key);
      else return find(t->r, key);
    }
  }
  bool find(T key){
    return find(root, key);
  }
  void dfs_t(){
    dfs_t(root);
    cout << endl;
  }
  void dfs_s(){
    dfs_s(root);
    cout << endl;
  }
  void dfs_t(Tree node){
    if(!node)return;
    if(node->l){
      dfs_t(node->l);
    }
    cout << " " << node->key;
    if(node->r){
      dfs_t(node->r);
    }
  }
  void dfs_s(Tree node){
    if(!node)return;
    cout << " " << node->key;
    if(node->l){
      dfs_s(node->l);
    }
    if(node->r){
      dfs_s(node->r);
    }
  }
};


int main(int argc, char const* argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> m;
  Treap<ll> tr;
  rep(i_, m){
    string s;
    cin >> s;
    if(s == "insert"){
      ll k, p;
      cin >> k >> p;
      tr.insert(k, p);
    }else if(s == "find"){
      ll k;
      cin >> k;
      if(tr.find(k))cout << "yes" << endl;
      else cout << "no" << endl;
    }else if(s == "delete"){
      ll k;
      cin >> k;
      if(tr.find(k))tr.erase(k);
    }else{
      tr.dfs_t();
      tr.dfs_s();
    }
  }
	return 0;
}

