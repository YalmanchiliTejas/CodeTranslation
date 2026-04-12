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
#include <complex>
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

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

const ll mod = 1000000007;

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

map<int, int> zip;
VI unzip;
void compress_coordinate(VI x){
    x.push_back(0);
    int n = x.size();
    REP(i,n) unzip.push_back(x[i]);
    sort(ALL(unzip));
    unzip.erase(unique(ALL(unzip)), unzip.end());
    REP(i,unzip.size()) zip[unzip[i]] = i;
}

const int N = 105;
ll dp[N][N];

int main() {
    int n;
    cin >> n;
    VI h(n);
    REP(i,n) h[i] = in();
    compress_coordinate(h);
    int m = unzip.size();

    REP(j,m){
        if (j == 0) dp[0][0] = powll(2, h[0]);
        else if (h[0] >= unzip[j]) dp[0][j] = powll(2, h[0] - unzip[j] + 1);
    }
    REP(j,m-1){
        dp[0][j] = (dp[0][j] - dp[0][j+1] + mod) % mod;
    }

    REP(i,n-1) REP(j,m){
        if (h[i] >= h[i+1]){
            if (unzip[j] < h[i+1]){
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
            }else{
                int x = zip[h[i+1]];
                dp[i+1][x] = (dp[i+1][x] + 2 * dp[i][j]) % mod;
            }
        }else{
            if (j < zip[h[i]]){
                dp[i+1][j] = (dp[i+1][j] + dp[i][j] * powll(2, h[i+1] - h[i])) % mod;
            }else{
                FOR(k,zip[h[i]],zip[h[i+1]]){
                    ll tmp = powll(2, h[i+1] - unzip[k]);
                    if (k < zip[h[i+1]]) tmp = (tmp + mod - powll(2, h[i+1] - unzip[k+1])) % mod;
                    dp[i+1][k] = (dp[i+1][k] + 2 * dp[i][j] * tmp) % mod;
                }
            }
        }
    }

    // REP(i,n-1){
    //     REP(j,m) cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    ll ans = 0;
    REP(j,m) ans = (ans + dp[n-1][j]) % mod;
    cout << ans << endl;

    return 0;
}