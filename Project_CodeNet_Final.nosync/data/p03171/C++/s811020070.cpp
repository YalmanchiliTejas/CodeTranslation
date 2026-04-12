#include<bits/stdc++.h>
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define p push
#define p1 pop
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define pi pair<ll,ll>
#define e 1000000007
using namespace std;
ll dp[3005][3005];
ll solve(ll i,ll j,ll arr[])
{
    if(i==j)
        return dp[i][j]=arr[i];
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j]=max(arr[i]-solve(i+1,j,arr),arr[j]-solve(i,j-1,arr));
}
int main(){
    ll n;cin>>n;
    ll arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    memset(dp,-1,sizeof(dp));
   cout<<solve(0,n-1,arr);
    return 0;
}