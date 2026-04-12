#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define fi first
#define se second
#define mod 998244353
#define all(v) v.begin(),v.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define go_t int t;cin>>t;for(int tt=1;tt<=t;tt++)
#define set_ar(arr,v) memset(arr,v,sizeof(arr))
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; // order_of_key
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf = 0x3f3f3f3f3f3f3f3fll;//4x10e18
const int maxx = 3000000;
#define PI 3.14159265
ll dp[3005][3005];
int main()
{
    fastio;
    int n,s;
    cin>>n>>s;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<3002;i++)for(int j=0;j<3002;j++)dp[i][j] = 0;
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=a[i]+1;j<3002;j++)
        {
            dp[i][j]+= dp[i-1][j-a[i]];
            dp[i][j]%=mod;
        }
        dp[i][a[i]]+=i;
        dp[i][a[i]]%=mod;
        //trace2(i,dp[i][s]);
        ans = ans + 1LL*dp[i][s]*(n-i+1);
        ans%=mod;
        for(int j=0;j<3002;j++)
        {
            dp[i][j]+= dp[i-1][j];
            dp[i][j]%=mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
