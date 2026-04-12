#include <bits/stdc++.h>
using namespace std;
#define TRACE(x) x
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mp make_pair
#define st first
#define nd second

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using pll = pair<ll, ll>;

void buff() { ios::sync_with_stdio( false ); cin.tie( nullptr ); }

constexpr ll MOD = 998'244'353;

inline ll pow_mod( ll a, ll b, ll mod = MOD) {
    ll res = 1; a %= mod; assert(b >= 0);
    for(;b;b>>=1) {
        if(b&1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}
constexpr int ms = 3013;
// End of template code!
long long dp[ms][ms];

int main() 
{
    buff();
    int n, S;
    cin >> n >> S;
    vector<long long> v(n + 1);
    for(int i = 1; i <= n; ++i) cin >> v[i];

    dp[0][0] = 1ll;
    long long ans = 0; 
    for(int i = 1; i <= n; ++i)
    {
        if(S >= v[i]) {
            long long good_R = (n - i + 1);
            long long add = (dp[i - 1][S - v[i]] * good_R) % MOD;
            ans = (ans + add) % MOD;
        }
        // agora tenho que fazer o update dos L's
        for(int j = 0; j < ms; ++j) {
            dp[i][j] = dp[i - 1][j]; 
            if(j >= v[i]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - v[i]]) % MOD;
            }
        }
        dp[i][0] = (dp[i][0] + 1) % MOD;
    }

    cout << ans << '\n';

    return 0;
}

