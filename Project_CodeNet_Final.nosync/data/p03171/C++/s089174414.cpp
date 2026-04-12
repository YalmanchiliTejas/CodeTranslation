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
#define endl "\n"
#define all(v) v.begin(),v.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define go_t int t;cin>>t;for(int tt=1;tt<=t;tt++)
#define set_ar(arr,v) memset(arr,v,sizeof(arr))
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; // order_of_key
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf = 0x3f3f3f3f3f3f3f3fll;//4x10e18
const int maxx = 3000000 , mod = 1000000007;
#define PI 3.14159265
ll dp[3005][3005][2];
ll a[3005];
ll solve(int l,int r,int turn)
{
    if(l==r)
    return dp[l][l][turn] = a[l]*turn;

    if(dp[l][r][turn]!=-1)return dp[l][r][turn];

    if(turn==1)
        return dp[l][r][1] = max(solve(l+1,r,0)+a[l],solve(l,r-1,0)+a[r]);
    return dp[l][r][0] = min(solve(l+1,r,1),solve(l,r-1,1));
}
int main()
{
    fastio;
    int n;
    cin>>n;
    ll sum = 0;
    set_ar(dp,-1);
    for(int i=1;i<=n;i++){cin>>a[i];sum+=a[i];}
    solve(1,n,1);
    cout<<(dp[1][n][1]-(sum-dp[1][n][1]))<<endl;
    return 0;
}
