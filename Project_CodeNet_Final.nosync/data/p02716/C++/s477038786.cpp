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
#define sz(x) (int)(x).size()
#define mp make_pair
#define fi first
#define se second 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using ld = long double;
using pll = pair<ll, ll>;

void buff() { ios::sync_with_stdio( false ); cin.tie( nullptr ); }

constexpr ll MOD = 1e9 + 7;

inline ll pow_mod( ll a, ll b, ll mod = MOD) {
    ll res = 1; a %= mod; assert(b >= 0);
    for(;b;b>>=1) {
        if(b&1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}


constexpr int ms = 1e5 + 13;

map< pii, long long > dp;
vector<ll> v;
ll padding = -MOD;
ll safe_min = padding * 1ll * ms;
int n;

ll solve(int cur_index, int remaining) {
    if(cur_index >= n && remaining > 0) return safe_min;
    if(cur_index >= n && remaining == 0) return 0;
    if(dp[{cur_index, remaining}]) return dp[{cur_index, remaining}];
    
    int quantos_tem_faltando = (n - cur_index + 1);
    int quantos_precisa = (remaining);
    int quantos_posso_botar = quantos_tem_faltando / 2 + !!(quantos_tem_faltando % 2);
    if(quantos_posso_botar < quantos_precisa) return dp[{cur_index,remaining}] = safe_min; // garantindo que o processo para nesse cara
    
    if(remaining == 0) return dp[{cur_index, 0}] = 0;    
    // agora tenho que escolher entre usar ou nao 
    ll ans = max( solve(cur_index + 1, remaining), solve(cur_index + 2, remaining - 1) + v[cur_index] );
    return dp[{cur_index,remaining}] = ans;
}
// End of template code!
int main() 
{
    buff();
    cin >> n;
    v.resize(n);
    long long extra = MOD;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        v[i] += extra; // garantindo que todo mundo esta positivo
    }

    cout << solve(0, n / 2) - (1ll * n / 2ll) * extra << '\n';
    return 0;
}

