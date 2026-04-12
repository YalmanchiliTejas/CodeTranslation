#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using llu=unsigned long long;
#define mod 1000000007
#define mode 998244353
#define PI 3.14159265358979323846
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mms(x,y) memset(x,y,sizeof(x))
#define pqm priority_queue<ll,vector<ll>,greater<ll>>
#define pb push_back
#define um unordered_map
#define pr pair
#define mm multimap
#define ms multiset
#define mp make_pair
#define vr vector
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define inf INT_MAX
#define ninf INT_MIN
#define ff first
#define ss second
#define gcd __gcd
ll dp[3005][3005][2];
int main()
{
    fast;
    ll t,n,m,i,j,k;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)cin>>a[i];
    for(i=1;i<=n;i++)dp[i][i][0]=a[i-1];
    for(i=2;i<=n;i++)
    {
        for(j=1;j+i-1<=n;j++)
        {
            dp[j][j+i-1][0]=max(dp[j][j+i-2][1]+a[j+i-2],dp[j+1][j+i-1][1]+a[j-1]);
            if(dp[j][j+i-2][1]+a[j+i-2]>dp[j+1][j+i-1][1]+a[j-1])
            dp[j][j+i-1][1]=dp[j][j+i-2][0];
            else dp[j][j+i-1][1]=dp[j+1][j+i-1][0];
        }
    }
    cout<<dp[1][n][0]-dp[1][n][1];
}
