#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
const long long MAXN = 1e6+5;
long long fact[MAXN];
long long dp[1005][1005];
long long inv[MAXN];
long long factinv[MAXN];
long long powe(long long x,long long y){
    long long z = 1;
   
    while(y>0){
        if(y%2 == 1){
            z*=x;
            z%=MOD;
        }
        x=x*x;
        x%=MOD;
        y/=2;
    }
    
    return z%MOD;
}
long long C(long long n,long long k){
    //cout<<(1LL*fact[k]*fact[n-k])%MOD<<endl;
    if (k < 0 || n < k) return 0;
    return ((1LL*(1LL*fact[n]*factinv[k])%MOD)*factinv[n-k])%MOD;
}
int main() {
    long long n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    fact[0] = 1;
    fact[1] = 1;
    inv[1] = 1;
    factinv[0] = 1;
    factinv[1] = 1;
    for(long long i=2;i<=n;i++){
        fact[i] = fact[i-1]*i;
        fact[i]%=MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        inv[i]%=MOD;
        factinv[i] = factinv[i-1]*inv[i];
        factinv[i]%=MOD;
    }
    dp[a-1][0] = 1;
    
    for(long long i=a;i<=b;i++){
        for(long long j=0;j<=n;j++){
            dp[i][j] = dp[i-1][j];
            for(long long k=c;k<=d;k++){
                if(j<(i*k)){
                    break;
                }
                
                long long val = 1LL*dp[i-1][j-(1LL*i*k)]*C(j,1LL*i*k);
                
                val%=MOD;
                 val*=1LL*fact[k*i];
               
                val%=MOD;
                
                val*=1LL*((powe(factinv[i],k)%MOD)*factinv[k])%MOD;
                val%=MOD;
                
                dp[i][j] += val;
                dp[i][j]%=MOD;
                
               
               
                
            }
           // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    cout<<dp[b][n]<<endl;
}