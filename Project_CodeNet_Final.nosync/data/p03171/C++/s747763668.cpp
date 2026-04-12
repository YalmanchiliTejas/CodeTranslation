#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n';
int lim=1e6;
int inf=1e9+7;
int n;
vector<vector<vector<ll> > > dp;
vector<ll> a;vector<vector<ll> > sum;

ll solve(int i,int j,int k){
    if(i>j){
        return 0;
    }
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }else{
        if(i==j){
            dp[i][j][k]=a[i];
            return a[i];
        }
        ll tmp1=solve(i+1,j,!k);ll tmp2=solve(i,j-1,!k);
        ll ans1=(a[i]+sum[i+1][j]-tmp1);
        ll ans2=(a[j]+sum[i][j-1]-tmp2);
        ll ans=max(ans1,ans2);
        dp[i][j][k]=ans;
        return ans;
    }
}

int main()
{   
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    dp.resize(n,vector<vector<ll> >(n,vector<ll>(2,-1)));
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sum.resize(n,vector<ll>(n,0));
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(j>0){
                sum[i][j]=sum[i][j-1]+a[j];    
            }else{
                sum[i][j]=a[j];
            }
        }
    }
    ll ans=solve(0,n-1,0);
    ans=2*ans-sum[0][n-1];
    cout<<ans<<ln;
}