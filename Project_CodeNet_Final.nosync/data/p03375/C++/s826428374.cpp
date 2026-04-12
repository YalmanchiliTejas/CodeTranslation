#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <assert.h>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef vector<double> VD;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

ll mod;
const int N = 4000;
ll fact[N], invf[N], two[N];

ll add(ll x, ll y){
    return (x+y)%mod;
}

ll mul(ll x, ll y){
    return (x%mod)*(y%mod)%mod;
}

ll powll(ll x, ll y){
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

ll dp[N][N];

int main() {
    ll n;
    cin >> n >> mod;

    fact[0] = invf[0] = two[0] = 1;
    FOR(i,1,N-1){
        fact[i] = (fact[i-1] * i) % mod;
        invf[i] = divll(invf[i-1], i);
        two[i] = (two[i-1] * 2) % (mod - 1);
    }

    dp[0][0] = 1;
    FOR(i,1,n){
        dp[i][0] = 1;
        FOR(j,1,i){
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] + j * dp[i-1][j]) % mod;
        }
    }

    // FOR(i,0,10){
    //     REP(j,i+1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    ll ans = 0;
    REP(k,n+1){
        ll tmp = 0;
        REP(i,k+1){
            tmp = (tmp + dp[k][i] * powll(2, (ll)(n - k) * i)) % mod;
        }
        tmp = (tmp * powll(2, two[n - k])) % mod;
        tmp = (tmp * nCr(n, k)) % mod;
        if (k % 2 == 0) ans = (ans + tmp) % mod;
        else ans = (ans - tmp + mod) % mod;
    }
    cout << ans << endl;

    return 0;
}
