#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint mod = 1e9 + 7;
#define all(x) (x).begin(), (x).end()
#define bitcount(n) __builtin_popcountl((lint)(n))
#define fcout cout << fixed << setprecision(15)
#define highest(x) (63 - __builtin_clzl(x))
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T = string, class U = char>int character_count(T text, U character){ int ans = 0; for(U i: text){ ans += (i == character); } return ans; }
lint power(lint base, lint exponent, lint module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ lint root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
struct position{ int y, x; }; position mv[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; // double euclidean(position first, position second){ return sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y)); }
template<class T, class U> string to_string(pair<T, U> x){ return to_string(x.first) + "," + to_string(x.second); } string to_string(string x){ return x; }
template<class itr> void array_output(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr first, itr last){ for(auto i = first; i != last; i++){ cin >> (*i); } }
template<class T> T gcd(T a, T b){ if(a && b){ return gcd(min(a, b), max(a, b) % min(a, b)); }else{ return a; }} template<class T> T lcm(T a, T b){ return a / gcd(a, b) * b; }
struct combination{ vector<lint> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2, mod); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } lint C(int p, int q) const{ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };
template<class itr> bool next_sequence(itr first, itr last, int max_bound){ itr now = last; while(now != first){ now--; (*now)++; if((*now) == max_bound){ (*now) = 0; }else{ return true; } } return false; }

template< class Monoid, class OperatorMonoid = Monoid >
struct RandomizedBinarySearchTree
{
    using F = function< Monoid(Monoid, Monoid) >;
    using G = function< Monoid(Monoid, OperatorMonoid) >;
    using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;
    using P = function< OperatorMonoid(OperatorMonoid, int) >;
    
    inline int xor128()
    {
        static int x = 123456789;
        static int y = 362436069;
        static int z = 521288629;
        static int w = 88675123;
        int t;
        
        t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }
    
    struct Node
    {
        Node *l, *r;
        int cnt;
        Monoid key, sum;
        OperatorMonoid lazy;
        
        Node() {}
        
        Node(const Monoid &k, const OperatorMonoid &p) : cnt(1), key(k), sum(k), lazy(p), l(nullptr), r(nullptr) {}
    };
    
    vector< Node > pool;
    int ptr;
    
    const Monoid M1;
    const OperatorMonoid OM0;
    const F f;
    const G g;
    const H h;
    const P p;
    
    RandomizedBinarySearchTree(int sz, const F &f, const Monoid &M1) :
    pool(sz), ptr(0), f(f), g(G()), h(H()), p(P()), M1(M1), OM0(OperatorMonoid()) {}
    
    RandomizedBinarySearchTree(int sz, const F &f, const G &g, const H &h, const P &p,
                               const Monoid &M1, const OperatorMonoid &OM0) :
    pool(sz), ptr(0), f(f), g(g), h(h), p(p), M1(M1), OM0(OM0) {}
    
    inline Node *alloc(const Monoid &key) { return &(pool[ptr++] = Node(key, OM0)); }
    
    virtual Node *clone(Node *t) { return t; }
    
    inline int count(const Node *t) { return t ? t->cnt : 0; }
    
    inline Monoid sum(const Node *t) { return t ? t->sum : M1; }
    
    inline Node *update(Node *t)
    {
        t->cnt = count(t->l) + count(t->r) + 1;
        t->sum = f(f(sum(t->l), sum(t->r)), t->key);
        return t;
    }
    
    Node *propagete(Node *t)
    {
        t = clone(t);
        if(t->lazy != OM0) {
            t->key = g(t->key, t->lazy);
            if(t->l) {
                t->l = clone(t->l);
                t->l->lazy = h(t->l->lazy, t->lazy);
                t->l->sum = f(t->l->sum, p(t->lazy, count(t->l)));
            }
            if(t->r) {
                t->r = clone(t->r);
                t->r->lazy = h(t->r->lazy, t->lazy);
                t->r->sum = f(t->r->sum, p(t->lazy, count(t->r)));
            }
            t->lazy = OM0;
        }
        return update(t);
    }
    
    Node *merge(Node *l, Node *r)
    {
        if(!l || !r) return l ? l : r;
        if(xor128() % (l->cnt + r->cnt) < l->cnt) {
            l = propagete(l);
            l->r = merge(l->r, r);
            return update(l);
        } else {
            r = propagete(r);
            r->l = merge(l, r->l);
            return update(r);
        }
    }
    
    pair< Node *, Node * > split(Node *t, int k)
    {
        if(!t) return {t, t};
        t = propagete(t);
        if(k <= count(t->l)) {
            auto s = split(t->l, k);
            t->l = s.second;
            return {s.first, update(t)};
        } else {
            auto s = split(t->r, k - count(t->l) - 1);
            t->r = s.first;
            return {update(t), s.second};
        }
    }
    
    Node *build(int l, int r, const vector< Monoid > &v)
    {
        if(l + 1 >= r) return alloc(v[l]);
        return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
    }
    
    Node *build(const vector< Monoid > &v)
    {
        ptr = 0;
        return build(0, (int) v.size(), v);
    }
    
    void dump(Node *r, typename vector< Monoid >::iterator &it)
    {
        if(!r) return;
        r = propagete(r);
        dump(r->l, it);
        *it = r->key;
        dump(r->r, ++it);
    }
    
    vector< Monoid > dump(Node *r)
    {
        vector< Monoid > v((size_t) count(r));
        auto it = begin(v);
        dump(r, it);
        return v;
    }
    
    string to_string(Node *r)
    {
        auto s = dump(r);
        string ret;
        for(int i = 0; i < s.size(); i++) ret += ", ";
        return (ret);
    }
    
    void insert(Node *&t, int k, const Monoid &v)
    {
        auto x = split(t, k);
        t = merge(merge(x.first, alloc(v)), x.second);
    }
    
    void erase(Node *&t, int k)
    {
        auto x = split(t, k);
        t = merge(x.first, split(x.second, 1).second);
    }
    
    Monoid query(Node *&t, int a, int b)
    {
        auto x = split(t, a);
        auto y = split(x.second, b - a);
        auto ret = sum(y.first);
        t = merge(x.first, merge(y.first, y.second));
        return ret;
    }
    
    void set_propagate(Node *&t, int a, int b, const OperatorMonoid &p)
    {
        auto x = split(t, a);
        auto y = split(x.second, b - a);
        y.first->lazy = h(y.first->lazy, p);
        t = merge(x.first, merge(propagete(y.first), y.second));
    }
    
    void set_element(Node *&t, int k, const Monoid &x)
    {
        t = propagete(t);
        if(k < count(t->l)) set_element(t->l, k, x);
        else if(k == count(t->l)) t->key = t->sum = x;
        else set_element(t->r, k - count(t->l) - 1, x);
        t = update(t);
    }
    
    
    int size(Node *t)
    {
        return count(t);
    }
    
    bool empty(Node *t)
    {
        return !t;
    }
    
    Node *makeset()
    {
        return (nullptr);
    }
};

template< class T >
struct OrderedMultiSet : RandomizedBinarySearchTree< T >
{
    using RBST = RandomizedBinarySearchTree< T >;
    using Node = typename RBST::Node;
    
    OrderedMultiSet(int sz) : RBST(sz, [&](T x, T y) { return x; }, T()) {}
    
    T kth_element(Node *t, int k)
    {
        if(k < RBST::count(t->l)) return kth_element(t->l, k);
        if(k == RBST::count(t->l)) return t->key;
        return kth_element(t->r, k - RBST::count(t->l) - 1);
    }
    
    virtual void insert_key(Node *&t, const T &x)
    {
        RBST::insert(t, lower_bound(t, x), x);
    }
    
    void erase_key(Node *&t, const T &x)
    {
        if(!count(t, x)) return;
        RBST::erase(t, lower_bound(t, x));
    }
    
    int count(Node *t, const T &x)
    {
        return upper_bound(t, x) - lower_bound(t, x);
    }
    
    int lower_bound(Node *t, const T &x)
    {
        if(!t) return 0;
        if(x <= t->key) return lower_bound(t->l, x);
        return lower_bound(t->r, x) + RBST::count(t->l) + 1;
    }
    
    int upper_bound(Node *t, const T &x)
    {
        if(!t) return 0;
        if(x < t->key) return upper_bound(t->l, x);
        return upper_bound(t->r, x) + RBST::count(t->l) + 1;
    }
};

int main(){
    int N;
    cin >> N;
    lint A[N];
    cins(A, A + N);
    pair<lint, int> sorted[N];
    OrderedMultiSet<int> orders(N);
    auto root = orders.makeset();
    for(int i = 0; i < N; i++){
        sorted[i] = {A[i], -i};
    }
    sort(sorted, sorted + N);
    int ans = 0, sz = 0;
    for(auto i: sorted){
        int pos = i.second;
        int LB = orders.lower_bound(root, pos);
        if(LB == sz){
            ans++, sz++;
        }else{
            int num = orders.kth_element(root, LB);
            orders.erase_key(root, num);
        }
        orders.insert_key(root, pos);
    }
    cout << ans << endl;
}
