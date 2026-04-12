#include<vector>
#include<iostream>
using namespace std;

using ll=long long;
const ll MOD=1e9+7;

vector<ll> fact;

ll powm(ll x,ll k){
    ll res=1;
    while(k){
        if(k&1) res=res*x%MOD;
        k>>=1;
        x=x*x%MOD;
    }
    return res;
}
ll inv(ll x){
    return powm(x,MOD-2);
}
void init(int n){
    fact.resize(n+1);
    fact[0]=1;
    for(int i=0;i<n;i++){
        fact[i+1]=fact[i]*(i+1)%MOD;
    }
}
int main(){
    int n;
    cin>>n;
    init(n);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<vector<ll>> dp(n+1,vector<ll>(n+1));
    dp[0][n]=1;
    auto comb=[](int n,int k){
        return fact[n]*inv(fact[k])%MOD*inv(fact[n-k])%MOD;
    };
    auto calc=[comb](int i,int j,int f){
        return comb(j,f*i)*fact[f*i]%MOD*inv(fact[f])%MOD*inv(powm(fact[i],f))%MOD;
    };

    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            if(a<=i+1 && i+1<=b){
                for(int f=c;f<=d;f++){
                    if(j-f*(i+1)<0) break;
                    (dp[i+1][j-f*(i+1)]+=calc(i+1,j,f)*dp[i][j])%=MOD;
                }
            }
            (dp[i+1][j]+=dp[i][j])%=MOD;
        }
    }
    
    cout<<dp[n][0]<<endl;
    return 0;
}
