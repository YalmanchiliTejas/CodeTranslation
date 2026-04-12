#include<bits/stdc++.h>
// __builtin_ctz : no of trailing zeros
#define ll long long
#define pp pair<ll,ll>
#define mod 1000000007
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
    ll n;cin >> n;ll a[n];
    for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
    }
    ll b[n];
    memset(b,0,sizeof(b));
    for (int i = 0; i < n; i+=2)
    {
      b[i]+=a[i];if(i)b[i]+=b[i-2];
    }
    ll dp[n];memset(dp,0,sizeof(dp));
    dp[0]=0;
    dp[1]=max(a[1],a[0]);
    for(ll i=2;i<n;i++)
    {
      dp[i]=max(a[i]+dp[i-2],(i%2)?(b[i-1]):(dp[i-1]));
    }
    cout << dp[n-1];
    }