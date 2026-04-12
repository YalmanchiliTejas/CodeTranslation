#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)
#define f first
#define s second
#define pb push_back
#define gap ' '
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define mod 1000000007

const int N=3005;
int n;
ll ara[N];
ll dp[N][N];
ll solve(int i,int l)
{
    if(i==n) return 0;
    int r=n-1-(i-l);
    if(dp[i][l]!=-1) return dp[i][l];
    dp[i][l]=max(ara[l]-solve(i+1,l+1),ara[r]-solve(i+1,l));
    return dp[i][l];
}
int main()
{
    fastio;
    cin>>n;
    for(int i=0;i<n;i++) cin>>ara[i];
    memset(dp,-1,sizeof dp);
    cout<<solve(0,0)<<endl;

}
