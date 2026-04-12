#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
const ll mod = 1e9+7;
const ll N = 3002;
ll dp[N][N],arr[N]={0};

ll solve(ll l,ll r,ll p)
{
    //cout<<l<<" "<<r<<" "<<p<<endl;
    if(l==r){
        if(p==0){
            dp[l][r] = arr[l];
        }
        else
            dp[l][r] = -1*arr[l];
        return dp[l][r];
    }
    if(dp[l][r]!=-1)
        return dp[l][r];
    ll x = solve(l+1,r,1-p);
    ll y = solve(l,r-1,1-p);
    if(p==0){
        x+=arr[l];
        y+=arr[r];
        dp[l][r] = max(x,y);
        return dp[l][r];
    }
    else{
        x-=arr[l];
        y-=arr[r];
        dp[l][r] = min(x,y);
        return dp[l][r];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    }
    cout<<solve(0,n-1,0)<<endl;
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
}
