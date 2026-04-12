#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int sz=3001;
ll dp[sz][sz][2];
ll solve(vector<ll>& picks,ll l,ll r,int turn){
    if(l>r){
        return 0;
    }
    if(dp[l][r][turn]!=0)
        return dp[l][r][turn];
    if(turn==1) // 1 stands for Taro
        dp[l][r][turn]=max(picks[l]+solve(picks,l+1,r,0),picks[r]+solve(picks,l,r-1,0));
    else // 1 stands for Jiro
        dp[l][r][turn]=min(solve(picks,l+1,r,1),solve(picks,l,r-1,1));
    return dp[l][r][turn];
}   

int main() {
	for(ll i=0;i<sz;++i)
        for(ll j=0;j<sz;++j)
            for(ll k=0;k<2;++k)
                dp[i][j][k]=0;
    ll n=0;cin>>n;
    vector<ll> picks(n,0);
    ll total_possible=0;
    for(int i=0;i<n;++i){
        cin>>picks[i];
        total_possible+=picks[i];
    }
    ll taro_score=solve(picks,0,n-1,1);
    ll jiro_score=total_possible-taro_score;
    cout<<taro_score-jiro_score<<'\n';
    return 0;
}
