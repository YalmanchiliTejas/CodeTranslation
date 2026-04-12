#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

#define mx 1000008

#define pii pair<int,int>
#define pi acos(-1.0)
#define pb push_back
#define ss second
#define ff first
typedef long long int ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
ll dp[3003][3003][2];
ll a[mx];
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
ll cal(ll i,ll j,ll ok)
{
    if(i==j){
        if(ok==0){
            return dp[i][j][0]=a[i];
        }
        else return dp[i][j][1]=-1*a[i];
    }
    if(dp[i][j][ok]!=-1) return dp[i][j][ok];
    if(ok==0){
        dp[i][j][ok]=max(cal(i+1,j,1)+a[i],cal(i,j-1,1)+a[j]);
    }
    else {
        dp[i][j][ok]=min(cal(i+1,j,0)-a[i],cal(i,j-1,0)-a[j]);
    }
    return dp[i][j][ok];
}
int main()
{
    ll n;
    memset(dp,-1,sizeof(dp));
    cin>>n;

    ll maxx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    cout<<cal(1,n,0)<<endl;
}
