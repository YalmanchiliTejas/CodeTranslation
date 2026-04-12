#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define cu continue
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf 1000000000
#define pll pair <ll,ll>
#define min_pq priority_queue <pll> ,vector <pll>, greater <pll> > > 
#define f first
#define s second
#define vll vector <ll>
#define dbg(n) cout<<n<<' ';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll dp[n][n];
    memset(dp,0,sizeof dp);
    for(ll i=0;i<n;i++)
        dp[i][i]=a[i];
    for(ll k=2;k<=n;k++)
    {
        for(ll i=0;i<n-k+1;i++)
        {
            ll j=i+k-1;
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1]<<'\n';
}       
