#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRInT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) (int) (v).size()

#define rep(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define trav(a, x) for(auto& a : x)

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define shandom_ruffle random_shuffle
#define funoredered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using funordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int InF = 0x3f3f3f3f;
constexpr int nInF = 0xc0c0c0c0;
constexpr double EPS = 1e-8;
constexpr ll MOD = 1000000007LL;

template <typename T>
using ordered_set = 
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

inline ll modPow( ll a, ll b, ll mod = MOD) {
    ll res = 1; a %= mod; assert(b >= 0);
    for(;b;b>>=1) {
        if(b&1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

inline int cmp_double( double x, double y, double tol = EPS) {
    return (x <= y + tol) ? ( x + tol < y) ? -1 : 0 : 1;
}

constexpr int ms = 3010;

long long dp[ms][ms];

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    vll V(n);
    
    for(auto& x : V) cin >> x;
    if(n == 1) {
        cout << V[0] << endl;
        return 0;
    }
    for(int i = 0; i < n - 1; ++i) {
        dp[i][i + 1] = max( V[i], V[i + 1]) - min(V[i], V[i + 1]); 
    }

    for(int i = 3; i <= n; ++i) {
        for(int st = 0; st + i - 1 < n; ++st) {
            dp[st][i + st - 1] = max( V[st] - dp[st + 1][i + st - 1], V[i + st - 1] - dp[st][i + st - 2] );
        }
    }
    
    cout << dp[0][n - 1] << endl;
    
    return 0;
}

