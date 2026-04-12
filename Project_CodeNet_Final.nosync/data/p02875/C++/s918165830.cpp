#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;
const int inf = 1e9;
const ll INF = 1e18;
const db eps = 1e-10;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define ep emplace
#define mem(a) memset(a, 0, sizeof(a))
#define copy(a, b) memcpy(a, b, sizeof(b))
#define PA cout << "pass\n"
#define lowbit(x) (x & -x)
#define all(x) x.begin(), x.end()
#define TM cout << db(clock()) / CLOCKS_PER_SEC << '\n'

const int mod = 998244353;
const int maxn = 1e7 + 233;
int fac[maxn], inv[maxn];

int pow_mod(int q, int w){
    int ret = 1;
    while(w){
        if(w & 1) ret = 1ll * ret * q % mod;
        q = 1ll * q * q % mod;
        w >>= 1;
    }
    return ret % mod;
}

int n;
int po[maxn];

int C(int x, int y){
    if(x < y) return 0;
    return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    po[0] = fac[0] = inv[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod, po[i] = (po[i - 1] + po[i - 1]) % mod;
    inv[n] = pow_mod(fac[n], mod - 2);
    for(int i = n - 1; i; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
    int res = 0;
    for(int i = n / 2 + 1; i <= n; i++) res = (res + 2ll * C(n, i) * po[n - i]) % mod;
    cout << (pow_mod(3, n) + mod - res) % mod << '\n';
    return 0;
}