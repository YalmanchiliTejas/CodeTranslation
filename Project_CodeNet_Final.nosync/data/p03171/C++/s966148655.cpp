#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<vector<ll>>dp(3001,vector<ll>(3001,-1));
ll a[3001];
ll F(ll L,ll r){
    if(L>r){
        return 0;
    }
    if(dp[L][r]!=-1){
        return dp[L][r];
    }
    ll x=a[L]+min(F(L+2,r),F(L+1,r-1));
    ll y=a[r]+min(F(L+1,r-1),F(L,r-2));
    ll profit=max(x,y);
    return dp[L][r]=profit;
}


int main(){
   // memset(dp,-1,sizeof(dp));
    ll n;
    cin>>n;
    ll sum=0;
    for(ll i=1;i<=n;i++){
       cin>>a[i];
       sum+=a[i];
    }
    ll val=F(1,n);
    ll rm=sum-val;
    cout<<val-rm;
    return 0;
    
}