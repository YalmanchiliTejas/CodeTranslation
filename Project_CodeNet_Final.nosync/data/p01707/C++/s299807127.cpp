#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for (ll i=(a);i<(b);i++)
#define RFOR(i,a,b) for (ll i=(b)-1;i>=(a);i--)
#define REP(i,n) for (ll i=0;i<(n);i++)
#define RREP(i,n) for (ll i=(n)-1;i>=0;i--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

const ll linf = 1e18;
const int inf = 1e9;
const double eps = 1e-12;
const double pi = acos(-1);

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    EACH(x,vec) is >> x;
    return is;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
    REP(i,vec.size()) {
        if (i) os << " ";
        os << vec[i];
    }
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector< vector<T> >& vec) {
    REP(i,vec.size()) {
        if (i) os << endl;
        os << vec[i];
    }
    return os;
}
// SegmentTree<int> seg(n, 0x7FFFFFFF, [](int a, int b){return min(a, b);});
template <class T>
class SegmentTree {
    using func_t = function<T(T, T)>;
    const int sz, n;
    const T id;
    func_t merge;
    vector<T> data;
    int expand(int n) const { return n == 1 ? n : expand((n + 1) / 2) * 2; }
public:
    SegmentTree(const vector<T> &init, T id, func_t merge) :
        sz(init.size()), n(expand(sz)), id(id), data(n * 2, id), merge(merge) {
        copy(begin(init), end(init), begin(data)+n);
        RREP(i, n) {
            data[i] = merge(data[i * 2 + 0], data[i * 2 + 1]);
        }
    }
    int size() const { return sz; }
    void update(int p, T val) {
        assert (0 <= p && p < sz);
        data[p += n] = val;
        while (p /= 2) data[p] = merge(data[p * 2], data[p * 2 + 1]);
    }
    T find(int l, int r) const {
        assert (0 <= l && l <= r && r <= sz);
        l += n; r += n;
        T res1 = id, res2 = id;
        while (l != r) {
            if (l % 2) res1 = merge(res1, data[l++]);
            if (r % 2) res2 = merge(data[--r], res2);
            l /= 2; r /= 2;
        }
        return merge(res1, res2);
    }
};

const ll mod = 1e9+7;
ll mul(ll a, ll b) {
    return a * b % mod;
}
ll add(ll a, ll b) {
    return (a + b) % mod;
}
ll sub(ll a, ll b) {
    return (a - b + mod) % mod;
}
ll power(ll x, ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i <<= 1) {
        if (i & n) res = mul(res, x);
        x = mul(x, x);
    }
    return res;
}
ll inv(ll n) {
    return power(n, mod-2);
}
ll divi(ll a, ll b) {
    return mul(a, inv(b));
}
vector<ll> fact;
void init_fact(ll n) {
    fact.assign(n+1, 1);
    FOR(i, 1, fact.size()) {
        fact[i] = mul(fact[i-1], i);
    }
}

ll comb(ll n, ll r) {
    assert(r >= 0);
    if (r > n) return 0;
    return divi(fact[n], mul(fact[r], fact[n-r]));
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    ll n, D, X;
    init_fact(10000);
    while (cin >> n >> D >> X, n || D || X) {
        vector<ll> combs(n+1);
        REP(r, n+1) {
            ll val = 1;
            REP(i, r) {
                val = mul(val, (D-i)%mod);
            }
            val = divi(val, fact[r]);
            combs[r] = val;
        }
        SegmentTree<ll> seg(vector<ll>(n+1, 0), 0, [](ll a, ll b) { return a + b; });
        seg.update(0, 1);
        ll ans = 0;
        REP(d, min<ll>(D, n+1)) RREP(i, n+1) {
            ll val = seg.find(max<ll>(0, i-X+1), i)%mod;
            seg.update(i, val);
            if (i == n) {
                ans = add(ans, mul(combs[d+1], val));
            }
        }
        cout << ans << endl;
    }
}