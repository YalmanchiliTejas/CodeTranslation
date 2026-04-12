#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
ll a[3005];
ll dp[3005][3005][2];
ll func(int i,int j,int k){
    if(i>j)
        return 0;

    if(dp[i][j][k]!=-1)
        return dp[i][j][k];

    ll ans;
    if(k==1)
        ans=max(func(i+1,j,2)+a[i],func(i,j-1,2)+a[j]);
    else
        ans=min(func(i+1,j,1)-a[i],func(i,j-1,1)-a[j]);

    return dp[i][j][k]=ans;
}   
int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>a[i];

    memset(dp,-1,sizeof dp);
    cout<<func(0,n-1,1);
}