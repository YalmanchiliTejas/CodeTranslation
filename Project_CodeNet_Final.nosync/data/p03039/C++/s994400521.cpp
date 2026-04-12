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
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef vector<double> VD;
typedef vector<VD> VVD;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

const ll mod = 1e9 + 7;

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
    return (x * powll(y,mod-2)) % mod;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll x = 1, y = 1;
    REP(i,k-2){
        x = (x * (n * m - 2 - i)) % mod;
        y = (y * (i + 1)) % mod;
    }
    x = divll(x, y);

    ll s = 0;
    for (ll i = 0; i <= n + m - 2; i++){
        s = (s + i * (min(m - 1, i) - max(0LL, i - n + 1) + 1)) % mod;
    }
    ll sum = 0;
    REP(j,m){
        sum = (sum + s) % mod;
        ll tmp = n * (-m + 2 * (j + 1));
        s = (s + tmp % mod) % mod;
        s = (s + mod) % mod;
    }
    ll all = 0;
    REP(i,n){
        all = (all + sum) % mod;
        ll tmp = (m * (-n + 2 * (i + 1))) % mod;
        tmp = (tmp * m) % mod;
        sum = (sum + tmp % mod) % mod;
        sum = (sum + mod) % mod;
    }
    all = divll(all, 2);
    ll ans = (all * x) % mod;
    cout << ans << endl;

    return 0;
}
