#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Pld = pair<ld, ld>;
using Vec = vector<ll>;
using VecP = vector<P>;
using VecB = vector<bool>;
using VecC = vector<char>;
using VecD = vector<ld>;
using VecS = vector<string>;
template <class T>
using Vec2 = vector<vector<T>>;
#define REP(i, m, n) for(ll i = (m); i < (n); ++i)
#define REPN(i, m, n) for(ll i = (m); i <= (n); ++i)
#define REPR(i, m, n) for(ll i = (m)-1; i >= (n); --i)
#define REPNR(i, m, n) for(ll i = (m); i >= (n); --i)
#define rep(i, n) REP(i, 0, n)
#define repn(i, n) REPN(i, 1, n)
#define repr(i, n) REPR(i, n, 0)
#define repnr(i, n) REPNR(i, n, 1)
#define all(s) (s).begin(), (s).end()
#define pb push_back
#define fs first
#define sc second
template <class T1, class T2>
bool chmax(T1 &a, const T2 b){if(a < b){a = b; return true;} return false;}
template <class T1, class T2>
bool chmin(T1 &a, const T2 b){if(a > b){a = b; return true;} return false;}
ll pow2(const int n){return (1LL << n);}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (const T &i : v) os << i << ' ';
    return os;
}
void co() { cout << '\n'; }
template <class Head, class... Tail>
void co(Head&& head, Tail&&... tail) {
    cout << head << ' ';
    co(forward<Tail>(tail)...);
}
void ce() { cerr << '\n'; }
template <class Head, class... Tail>
void ce(Head&& head, Tail&&... tail) {
    cerr << head << ' ';
    ce(forward<Tail>(tail)...);
}
void sonic(){ios::sync_with_stdio(false); cin.tie(0);}
void setp(const int n){cout << fixed << setprecision(n);}
constexpr int INF = 1000000001;
constexpr ll LINF = 1000000000000000001;
constexpr ll MOD = 1000000007;
constexpr ll MOD_N = 998244353;
constexpr ld EPS = 1e-11;
const double PI = acos(-1);

struct Doubling {
    const int sz = 64;
    int n;
    vector<vector<ll>> data;
    vector<vector<ll>> sum;

    Doubling(int _n) : n(_n) {
        data.resize(sz);
        for (size_t i = 0; i < sz; ++i) {
            data[i].resize(n);
        }
        sum.resize(sz);
        for (size_t i = 0; i < sz; ++i) {
            sum[i].resize(n);
        }
    }

    void build(vector<ll> v) {
        for (size_t i = 0; i < n; ++i) {
            data[0][i] = v[i];
        }
        
        for (size_t i = 0; i < sz - 1; ++i) {
            for (size_t j = 0; j < n; ++j) {
                data[i + 1][j] = data[i][data[i][j]];
            }
        }
        
        for (size_t i = 0; i < n; ++i) {
            sum[0][i] = i;
        }
        
        for (size_t i = 0; i < sz - 1; ++i) {
            for (size_t j = 0; j < n; ++j) {
                sum[i + 1][j] = sum[i][j] + sum[i][data[i][j]];
            }
        }
    }

    ll solve(ll f, ll k) {
        int cnt = 0;
        ll res = 0;
        while (k) {
            if (k & 1){
                res += sum[cnt][f];
                f = data[cnt][f];
            }
            k >>= 1;
            ++cnt;
        }
        return res;
    }
};

int main(void) {
    ll n, x, m;
    cin >> n >> x >> m;

    Vec a(m);
    rep(i, m) a[i] = i * i % m;

    Doubling db(m);
    db.build(a);
    // rep(i, n) ce(db.solve(x, i));
    co(db.solve(x, n));

    return 0;
}