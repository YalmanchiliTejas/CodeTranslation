#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int n, m;
int l[200100], r[200100];
ll a[200100];

vector<int> lidx[200100];
vector<int> ridx[200100];

// Range Add Query
template<typename T>
class SegmentTree {
    class Node {
    public:
        ll l, r;
        T data;
        T lazy;
        Node* child_L;
        Node* child_R;
        Node(ll l, ll r, T data) {
            this->l = l;
            this->r = r;
            this->data = data;
            this->lazy = 0;
            this->child_L = nullptr;
            this->child_R = nullptr;
        }

        void lazy_evaluate() {
            //this->data += this->lazy * (this->r - this->l); // sum
            this->data += this->lazy;                       // min, max
            if (this->r - this->l > 1) {
                if (this->child_L == nullptr) {
                    ll mid = (this->l + this->r) / 2;
                    this->child_L = new Node(this->l, mid, init);
                    this->child_R = new Node(mid, this->r, init);
                }
                this->child_L->lazy += this->lazy;
                this->child_R->lazy += this->lazy;
            }
            this->lazy = 0;
        }
    };

    Node* root;
    ll N;
    static const T init = -1e16;
    T op(const T& a, const T& b) {
        return max(a, b);
    }
public:
    SegmentTree(ll n) {
        this->N = n;
        this->root = new Node(0, n, init);
    }

    void update(Node* node, ll k, T a) {
        if (node->l <= k && k < node->r) {
            if (node->l == k && node->r == k+1) {
                node->data = a;
            } else {
                node->lazy_evaluate();
                update(node->child_L, k, a);
                update(node->child_R, k, a);
                node->data = op(node->child_L->data, node->child_R->data);
            }
        } else {
            node->lazy_evaluate();
        }
    }
    void update(ll k, T a) {
        update(this->root, k, a);
    }

    void add(Node* node, ll k, T a) {
        if (node->l <= k && k < node->r) {
            if (node->l == k && node->r == k+1) {
                node->lazy_evaluate();
                node->data += a;
            } else {
                node->lazy_evaluate();
                add(node->child_L, k, a);
                add(node->child_R, k, a);
                node->data = op(node->child_L->data, node->child_R->data);
            }
        } else {
            node->lazy_evaluate();
        }
    }
    void add(ll k, T a) {
        add(this->root, k, a);
    }

    void add_range(Node* node, ll l, ll r, T a) {        
        if (node->r <= l || r <= node->l) {
            node->lazy_evaluate();
            return;
        }
        if (l <= node->l && node->r <= r) {
            node->lazy += a;
            node->lazy_evaluate();
        } else {
            node->lazy_evaluate();
            add_range(node->child_L, l, r, a);
            add_range(node->child_R, l, r, a);
            node->data = op(node->child_L->data, node->child_R->data);
        }
    }
    void add_range(ll l, ll r, T a) {
        if (l < r)
            add_range(this->root, l, r, a);
    }

    T query(Node* node, ll l, ll r) {
        if (node == nullptr || node->r <= l || r <= node->l) return init;
        node->lazy_evaluate();
        if (l <= node->l && node->r <= r) return node->data;
        return op(query(node->child_L, l, r), query(node->child_R, l, r));
    }
    
    T query(ll l, ll r) {
        return query(this->root, l, r);
    }

    T get(ll i) {
        return query(this->root, i, i+1);
    }
};

ll solve() {
    for (int i = 0; i < m; i++) {
        lidx[l[i]].push_back(i);
        ridx[r[i]].push_back(i);
    }

    SegmentTree<ll> st(n+1);
    st.update(0, 0);
    for (int i = 1; i <= n; i++) {
        for (int idx : lidx[i]) {
            st.add_range(0, l[idx], a[idx]);
        }
        ll v1 = st.query(0, i);
        st.update(i, v1);
        for (int idx : ridx[i]) {
            st.add_range(0, l[idx], -a[idx]);
        }        
    }
    return st.query(0, n+1);
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> a[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
