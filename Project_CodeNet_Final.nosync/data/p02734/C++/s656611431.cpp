#include<bits/stdc++.h>
// __builtin_ctz : no of trailing zeros
#define ll long long
#define pp pair<ll,ll>
#define mod 998244353
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define sa(a,n) for(int i =0 ; i<n ; i++) cin>>a[i]
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define scan() int n; cin>>n ; int a[n]; for(int i = 0 ; i<n ; i++) cin>>a[i]
#define print(a,n) for(int i = 0 ; i < n ; i++) cout<<a[i]<<' '
using namespace std;
ll max(ll x, ll y)
{
    return x>y ? x : y;
}
ll min(ll x, ll y)
{
    return x<y ? x : y;
}
void _(ll&a , ll b)
{
    a=(a%mod+b%mod)%mod;
    a=(a+mod)%mod;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,s,p;
    cin >> n >> s ;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
    	cin >> a[i];
    }
    ll dp[n+1][s+1];ll ans=0;
    memset(dp, 0, sizeof(dp));
    // for(ll i=0;i<=n;i++)
    // {
    // 	dp[i][0]=i;
    // }
    for(ll i=1;i<=n;i++)
    {
    	for(ll j=1;j<=s;j++)
    	{
    		dp[i][j]=dp[i-1][j];ll d=0;
    		if(j>a[i-1]){_(dp[i][j],dp[i-1][j-a[i-1]]);_(d,dp[i-1][j-a[i-1]]);}
    		else if(j==a[i-1]){_(dp[i][j],i);_(d,i);}
    		if(j==s)_(ans,(d*(n-i+1))%mod);
    	}
    }
    //cout << dp[1][1] << " ";
    // for(ll i=1;i<=n;i++)
    // {
    // 	for(ll j=0;j<=s;j++)
    // 	{
    // 		cout << dp[i][j] << " ";
    // 	}
    // 	cout << "\n";
    // }
    cout << ans;
    }