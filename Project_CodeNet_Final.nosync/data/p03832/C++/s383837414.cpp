#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <climits>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define pb push_back
#define sz(s) (int)s.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)

typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = (ll)1e9 + 7;
const int N = (int)1e5 + 7;
ll n,a,b,c,d, fac[N], invfac[N], dp[1001][1001];

ll mod_pow(ll base, ll e){
    ll ret =1;
    while(e){
        if(e%2) ret = (ret*base)%MOD;
        base = (base*base)%MOD;
        e /= 2;
    }
    return ret;
}

ll inv(ll x){
    return mod_pow(x, MOD-2);
}

ll solve(ll left, ll i){
    
    if(left == 0) return 1;
    
    if(i > b || left < 0) return 0;
    
    if(dp[left][i] != -1) return dp[left][i];
    
    ll ret = solve(left, i+1);
    for(ll j=c;j<=d;j++){
        ll s = i*j;
        if(s > left) break;
        ll tmp = mod_pow(invfac[i], j);
        tmp = (tmp*invfac[j])%MOD;
        tmp = (tmp*solve(left-s, i+1))%MOD;
        ret += tmp;
        ret %= MOD;
    }
    return dp[left][i] = ret;
}

int main() {
    cin >> n >> a >> b >> c >> d;
    
    fac[0] = 1;
    for1(i,1000) fac[i] = (fac[i-1]*i)%MOD;
    forn(i,1001) invfac[i] = inv(fac[i]);
    
    memset(dp,-1,sizeof dp);
    ll ret = solve(n, a)*fac[n];
    ret %= MOD;
    cout << ret <<endl;
    return 0;
}