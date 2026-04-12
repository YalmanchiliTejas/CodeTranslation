#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF 1000000000
#define MOD 1000000007
#define ll long long
#define NCKMAX 100000
using namespace std;
int n,a,b,c,d;
vector<ll> dp(1001),_dp(1001);
ll fact[NCKMAX];
void nckinit(){
    ll x=1;
    fact[0]=1;
    for (int i=1; i<NCKMAX; i++){
        (x*=i)%=MOD;
        fact[i]=x;
    }
}
int modpow(ll x,ll y){
    if (y==0){
        return 1;
    }else if (y==1){
        return x%MOD;
    }else if (y%2==0){
        ll z=modpow(x,y/2);
        return z*z%MOD;
    }else{
        ll z=modpow(x,y/2);
        return (z*z%MOD)*x%MOD;
    }
}
int inv(ll x){
    return modpow(x,MOD-2);
}
int nck(ll x,ll y){
    ll ret=fact[x];
    (ret*=inv(fact[y]))%=MOD;
    (ret*=inv(fact[x-y]))%=MOD;
    return ret;
}
ll solve(int x,int y,int z){
    ll ret=fact[n-z];
    (ret*=inv(fact[n-z-x*y]))%=MOD;
    return ret;
}
ll solve2(int x,int y){
    ll ret=modpow(x,y);
    (ret*=inv(fact[y]))%=MOD;
    return ret;
}
int main(){
    nckinit();
    cin>>n>>a>>b>>c>>d;
    dp[0]=1;
    for (int x=a;x<b+1;x++){    //何人グループまで作るか
        _dp=dp;
        ll xx=inv(fact[x]);
        for (int y=c;y<d+1;y++){    //x人で何グループ作るか
            if (x*y>n) break;
            ll s=solve2(xx,y);
            for (int z=0;z+x*y<n+1;z++){
                (_dp[z+x*y]+=(dp[z]*s%MOD)*solve(x,y,z)%MOD)%=MOD;
            }
        }
        dp=_dp;
    }
    cout<<dp[n]%MOD<<endl;
    return 0;
}