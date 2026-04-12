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
#include <algorithm>
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

const ll mod = 1000000007;
const int N = 1010;
ll fact[N], invf[N];

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

ll dp[1001][1001];

int main() {
    fact[0] = invf[0] = 1;
    FOR(i,1,N-1){
        fact[i] = (fact[i-1] * i) % mod;
        invf[i] = divll(invf[i-1], i);
    }

    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    dp[a-1][n] = 1;
    FOR(x,a,b) REP(j,n+1){
        dp[x][j] = (dp[x][j] + dp[x-1][j]) % mod;
        ll tmp = dp[x-1][j];
        REP(y,c) tmp = (tmp * nCr(j-y*x, x)) % mod;
        for (int y = c; y <= d && x * y <= j; y++){
            dp[x][j-x*y] = (dp[x][j-x*y] + tmp * invf[y]) % mod;
            tmp = (tmp * nCr(j-y*x, x)) % mod;
        }
    }

    // FOR(x,a,b){
    //     REP(j,n+1) cout << dp[x][j] << " ";
    //     cout << endl;
    // }

    cout << dp[b][0] << endl;

    return 0;
}
