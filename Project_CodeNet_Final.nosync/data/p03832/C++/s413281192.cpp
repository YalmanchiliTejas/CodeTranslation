#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF 1000000000000000
#define MOD 1000000007
#define EPS 1e-10
#define MAX_N (1<<19)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,P> PP;

ll n, a, b, c, d;
ll dp[1001][1001];
ll kai[100000];

ll mod_pow(ll x, ll y){
    ll ret = 1;
    while(y){
        if(y&1) ret = ret*x%MOD;
        x = x*x%MOD;
        y /= 2;
    }
    return ret;
}

ll conb(ll x, ll y){
    ll ret = 1;
    ll z = x-y;
    ret = kai[x];
    ret = ret*mod_pow(kai[y],MOD-2)%MOD;
    ret = ret*mod_pow(kai[z],MOD-2)%MOD;
    return ret;
}

int main(){
    kai[0] = 1;
    for(int i = 1; i< 100000; i++) kai[i] = kai[i-1]*i%MOD;
    cin >> n >> a >> b >> c >> d;
    dp[0][0] = kai[n];
    for(int i = a; i <= b; i++){
        int ii = i-a;
        rep(j,n+1) dp[ii+1][j] = dp[ii][j];
        ll del = mod_pow(kai[i],c);
        for(int j = c; j <= d; j++){
            for(int k = i*j; k <= n; k++){
                ll add = dp[ii][k-i*j]*mod_pow(del,MOD-2)%MOD;
                add = add*mod_pow(kai[j],MOD-2)%MOD;
                dp[ii+1][k] += add;
                
            }
            del = del*kai[i]%MOD;
        }
        for(int k = 0; k <= n; k++) dp[ii+1][k] %= MOD;
    }
    cout << dp[b-a+1][n] << endl;
}
