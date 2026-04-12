#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1e9+7;

ll powm(ll x,ll k){
    ll res=1;
    while(k){
        if(k&1) res=(res*x)%MOD;
        x=(x*x)%MOD;
        k>>=1;
    }
    return res;
}
ll inv(ll x){
    return powm(x,MOD-2);
}
ll comb(ll n,ll k){
    ll res=1;
    for(int i=0;i<k;i++){
        res*=(n-i)%MOD;
        res%=MOD;
    }
    for(int i=0;i<k;i++){
        res*=inv(i+1);
        res%=MOD;
    }
    return res;
}
int main(){
    ll n,d,x;
    while(cin>>n>>d>>x,n){
        vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            vector<ll> sum(n+2,0);
            partial_sum(dp[i].begin(),dp[i].end(),sum.begin()+1,[](int x,int y){return (x+y)%MOD;});
            for(int j=0;j<=n;j++){
                dp[i+1][j]=(sum[j+1]+MOD-sum[max(j-x+2,0LL)])%MOD;
            }
        }
        ll res=0;
        for(int i=1;i<=min(n,d);i++){
            res+=(comb(d,i)*dp[i][n-i])%MOD;
            res%=MOD;
        }
        cout<<(res+MOD)%MOD<<endl;
    }

    return 0;   
}
