#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
using namespace std;
int MOD = 1000000007;
ll bitpow(ll x,ll n){
    ll ans = 1;
    while(n > 0){
        if(n%2 == 1) ans = ans * x % MOD;
        x = x * x %MOD;
        n = n >> 1;
    }
    return ans;
}
#define N 200001
int fac[N+1];
int inv[N+1];
ll COM(ll n,ll k){
    return fac[n]*inv[k]%MOD*inv[n-k]%MOD;
}
    
signed main(){
    int n,m,k;
    cin >> n >> m >> k;
    fac[0] = 1;
    inv[0] = 1;
    for(int i = 1;i <= N;i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = bitpow(fac[i],MOD-2)%MOD;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            ans += (n-i+1)*(m-j+1)*(i+j-2)%MOD;
            ans %= MOD;
            if(i != 1 && j != 1){
                ans += (n-i+1)*(m-j+1)*(i+j-2)%MOD;
                ans %= MOD;
            }
        }
    }
    ans *= COM(n*m-2,k-2);
    
    
    cout << ans%MOD << endl;

    return 0;
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://cf17-final-open.contest.atcoder.jp/tasks/cf17_final_a
// rm -r -f test;oj dl http://abc127.contest.atcoder.jp/tasks/abc127_a