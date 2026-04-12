#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <functional>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

const ll mod = 998244353;
const int N = 5000010;
ll fact[N], invf[N];

ll add(ll x, ll y){
    return (x+y)%mod;
}

ll mul(ll x, ll y){
    return (x%mod)*(y%mod)%mod;
}

ll powll(ll x, ll y){
    x %= mod;
    ll res = 1LL;
    while(y){
        if (y & 1LL)
            res *= x;
        res %= mod;
        x = (x*x) % mod;
        y >>= 1LL;
    }
    return res;
}

ll divll(ll x, ll y){
    x %= mod;
    return (x * powll(y,mod-2)) % mod;
}

ll nPr(ll n, ll r){
    if (n < r || r < 0) return 0;
    return mul(fact[n], invf[n-r]);
}

ll nCr(ll n, ll r){
    if (n < r || r < 0) return 0;
    return mul(mul(fact[n], invf[r]), invf[n-r]);
}

void init_f(){
    fact[0] = 1;
    FOR(i,1,N-1){
        fact[i] = (fact[i-1] * i) % mod;
    }
    invf[N-1] = divll(1, fact[N-1]);
    FORR(i,N-1,1){
        invf[i-1] = (invf[i] * i) % mod;
    }
}

int main() {
    ll n;
    cin >> n;
    ll m = n / 2, all = 1;
    REP(i,n) all = (all * 3) % mod;

    init_f();

    VL two(m + 1);
    two[0] = 1;
    REP(i,m) two[i + 1] = (2 * two[i]) % mod;

    VL cnt(m + 1);
    for (ll x = 0; x <= m; x++){
        cnt[x] = (nCr(m, x) * two[m - x]) % mod;
    }
    VL sum(m + 1);
    sum[m] = cnt[m];
    FORR(i,m-1,0) sum[i] = (cnt[i] + sum[i + 1]) % mod;

    // FOR(i,0,m) cout << cnt[i] << " ";
    // cout << endl;
    // FOR(i,0,m) cout << sum[i] << " ";
    // cout << endl;
    ll bad = 0;
    FOR(x,1,m){
        ll y = m + 1 - x;
        (bad += cnt[x] * sum[y]) %= mod;
        // cout << cnt[x] * sum[y] << endl;
    }
    bad = (2 * bad) % mod;

    ll ans = (all - bad + mod) % mod;
    cout << ans << endl;

    return 0;
}
