#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;

const int MAX_N=1001;
const int mod=1000000007;
ll fact[MAX_N+1];
ll inv[MAX_N+1],finv[MAX_N+1];
int fact_init(ll n,ll p){
    if(fact[0]==0){
        fact[0]=1;
        FOR(i,1,n+1) fact[i]=fact[i-1]*i%p;
    }
    return 0;
}
int inv_init(ll n,ll p){
    inv[1]=1;
    fact[0]=fact[1]=finv[0]=finv[1]=1;
    FOR(i,2,n+1){
        inv[i]=p-(p/i)*inv[p%i]%p;
        fact[i]=fact[i-1]*i%p;
        finv[i]=finv[i-1]*inv[i]%p;
    }
    return 0;
}
ll comb_pow(ll n,ll k,ll p){
    if(k<0||n<k) return 0;
    //return finv[k]*finv[n-k]%p*fact[n]%p;
    return finv[n-k]*fact[n]%p;
}

ll dp[1001][1001];
int main(){
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    inv_init(n,mod);
    dp[a-1][0]=1;
    FOR(i,a,b+1)FOR(j,0,n+1){
        dp[i][j]+=dp[i-1][j];
        dp[i][j]%=mod;
        ll mul=1;
        FOR(k,1,d+1){
            if(j-k*i>=0){
                mul*=finv[i];mul%=mod;
                if(k>=c){
                    dp[i][j]+=dp[i-1][j-k*i]*comb_pow(n-j+k*i,k*i,mod)%mod*mul%mod*finv[k]%mod;
                    dp[i][j]%=mod;
                }
            }
            else break;
        }
    }
    cout<<dp[b][n]<<endl;
    return 0;
}