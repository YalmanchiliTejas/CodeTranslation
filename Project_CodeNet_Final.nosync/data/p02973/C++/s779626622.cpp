#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <bitset>

using namespace std;
using ll = long long;
using ld = long double;
const ll mod =  1000000007;
const ll inf = 1e18;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP_FROM(i, j, n) for (ll i = (j); i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll power(ll base, ll exponent){ if(exponent % 2){ return power(base, exponent - 1) * base % mod; }else if(exponent){ ll root_ans = power(base, exponent / 2); return root_ans * root_ans % mod; }else{ return 1; }}
ll inverse(ll x){ return power(x, mod - 2);}
ll gcd(ll a, ll b) {if(a < b) gcd(b, a);ll r;while(r=a%b) {a=b;b=r;}return b;}
template<typename T> ll sum(T begin, T end) {return accumulate(begin, end, 0ll);}
struct combination{ vector<ll> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } ll C(int p, int q) const{ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };


int bsearch(const vector<ll>& a, ll x){
  int lft = 0;
  int rgt = a.size();
  while (rgt - lft > 1) {
    int mid = (lft + rgt) / 2;
    if(a[mid] < x) {
      lft = mid;
    }
    else {
      rgt = mid;
    }
  }
  return lft;
}
template<class VAL> struct RBST {
    VAL SUM_UNITY = 0;                              // to be set

    unsigned int randInt() {
        static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
        unsigned int tt = (tx ^ (tx << 11));
        tx = ty; ty = tz; tz = tw;
        return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
    }

    struct NODE {
        NODE *left, *right;
        VAL val;                        // the value of the node
        int size;                       // the size of the subtree 
        VAL sum;                        // the value-sum of the subtree

        NODE() : val(SUM_UNITY), size(1), sum(SUM_UNITY) {
            left = right = NULL;
        }

        NODE(VAL v) : val(v), size(1), sum(v) {
            left = right = NULL;
        }

        /* additional update */
        inline void update() {

        }

        /* additional lazy-propagation */
        inline void push() {

            /* ex: reverse */
            /*
            if (this->rev) {
            swap(this->left, this->right);
            if (this->left) this->left->rev ^= true;
            if (this->right) this->right->rev ^= true;
            this->rev = false;
            }
            */
        }
    };


    ///////////////////////
    // root
    ///////////////////////

    NODE* root;
    RBST() : root(NULL) { }
    RBST(NODE* node) : root(node) { }


    ///////////////////////
    // basic operations
    ///////////////////////

    /* size */
    inline int size(NODE *node) {
        return !node ? 0 : node->size;
    }
    inline int size() {
        return this->size(this->root);
    }

    /* sum */
    inline VAL sum(NODE *node) {
        return !node ? SUM_UNITY : node->sum;
    }
    inline VAL sum() {
        return this->sum(this->root);
    }

    /* update, push */
    inline NODE* update(NODE *node) {
        node->size = size(node->left) + size(node->right) + 1;
        node->sum = sum(node->left) + sum(node->right) + node->val;
        node->update();
        return node;
    }

    inline void push(NODE *node) {
        if (!node) return;
        node->push();
    }

    /* lower_bound */
    inline int lowerBound(NODE *node, VAL val) {
        push(node);
        if (!node) return 0;
        if (val <= node->val) return lowerBound(node->left, val);
        else return size(node->left) + lowerBound(node->right, val) + 1;
    }
    inline int lowerBound(VAL val) {
        return this->lowerBound(this->root, val);
    }

    /* upper_bound */
    inline int upperBound(NODE *node, VAL val) {
        push(node);
        if (!node) return 0;
        if (val >= node->val) return size(node->left) + upperBound(node->right, val) + 1;
        else return upperBound(node->left, val);
    }
    inline int upperBound(VAL val) {
        return this->upperBound(this->root, val);
    }

    // pytran
    inline int upperBoundVal(NODE *node, VAL val) {
        push(node);
        if (!node) return 0;
        if (val >= node->val) return size(node->left) + upperBound(node->right, val) + 1;
        else return upperBound(node->left, val);
    }

    /* count */
    inline int count(VAL val) {
        return upperBound(val) - lowerBound(val);
    }

    /* get --- k: 0-index */
    inline VAL get(NODE *node, int k) {
        push(node);
        if (!node) return -1;
        if (k == size(node->left)) return node->val;
        if (k < size(node->left)) return get(node->left, k);
        else return get(node->right, k - size(node->left) - 1);
    }
    inline VAL get(int k) {
        return get(this->root, k);
    }


    ///////////////////////
    // merge-split
    ///////////////////////

    NODE* merge(NODE *left, NODE *right) {
        push(left);
        push(right);
        if (!left || !right) {
            if (left) return left;
            else return right;
        }
        if (randInt() % (left->size + right->size) < left->size) {
            left->right = merge(left->right, right);
            return update(left);
        }
        else {
            right->left = merge(left, right->left);
            return update(right);
        }
    }
    void merge(RBST add) {
        this->root = this->merge(this->root, add.root);
    }
    pair<NODE*, NODE*> split(NODE* node, int k) { // [0, k), [k, n)
        push(node);
        if (!node) return make_pair(node, node);
        if (k <= size(node->left)) {
            pair<NODE*, NODE*> sub = split(node->left, k);
            node->left = sub.second;
            return make_pair(sub.first, update(node));
        }
        else {
            pair<NODE*, NODE*> sub = split(node->right, k - size(node->left) - 1);
            node->right = sub.first;
            return make_pair(update(node), sub.second);
        }
    }
    RBST split(int k) {
        pair<NODE*, NODE*> sub = split(this->root, k);
        this->root = sub.first;
        return RBST(sub.second);
    }


    ///////////////////////
    // insert-erase
    ///////////////////////

    void insert(const VAL val) {
        pair<NODE*, NODE*> sub = this->split(this->root, this->lowerBound(val));
        this->root = this->merge(this->merge(sub.first, new NODE(val)), sub.second);
    }

    void erase(const VAL val) {
        if (!this->count(val)) return;
        pair<NODE*, NODE*> sub = this->split(this->root, this->lowerBound(val));
        this->root = this->merge(sub.first, this->split(sub.second, 1).second);
    }


    ///////////////////////
    // debug
    ///////////////////////

    void print(NODE *node) {
        if (!node) return;
        push(node);
        print(node->left);
        cout << node->val << " ";
        print(node->right);
    }
    void print() {
        cout << "{";
        print(this->root);
        cout << "}" << endl;
    }
};

signed main() {
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> a(n);
  RBST<ll> b;
  map<ll, ll> c;
  REP(i, n) cin >> a[i];
  // REP(i, n) b.insert(a[i]);
  // REP(i, 10) {
  //   cout << i << ":" << b.upperBound(i) << endl;
  // }
  // cout << "---" << endl;
  // REP(i, 3) {
  //   cout << i << ":" << b.get((int)i) << endl;
  // }
  for(int i = n-1; i>=0 ;i--) {
    int index  = b.upperBound(a[i]);
    if(index == b.size()) {
      b.insert(a[i]);
      c[a[i]]++;
      continue;
    } 
    ll val = b.get(index);
    if(val == a[i]) {
      c[a[i]]++;
      continue;
    }
    b.erase(val);
    c[val]--;
    b.insert(a[i]);
    c[a[i]]++;
  }
  // b.print();
  ll ans = 0;
  for(const auto& i: c) ans += i.second;
  // for(const auto& i: c) cout << i.first << ":" << i.second << endl;
  cout << ans << endl;
  return 0;
}
