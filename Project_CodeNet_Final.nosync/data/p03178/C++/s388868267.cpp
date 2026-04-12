#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define mp make_pair
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
typedef long long ll;
using namespace __gnu_pbds;
typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll> >,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
/* ll t = 0;
ordered_multiset me;
...
me.insert({x, t++});
me.erase(me.lower_bound({x, 0}));
cout << me.order_of_key({x, 0}) << "\n";

///////////   t is insertion time
*/
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
typedef long double lld;
lld pi=3.14159265358;
ll powr(ll a,ll b)
{
    ll c=1;
    ll i;
    for(i=0;i<b;i++)
        c*=a;
    return c;
}
ll hell=1000000007;
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());  put as first line of main
ll dp[10005][101][2];
string s;
ll m,n;
ll f(ll i,ll abtakmod,ll flag) // i pe ho, abtakmod is mod till now, f;
{
    if(i==n && abtakmod==0)
        return 1;
    if(i==n && abtakmod!=0)
        return 0;
    if(dp[i][abtakmod][flag]!=-1)
        return dp[i][abtakmod][flag];
    ll ans=0;
    ll till,j;
    if(flag==0)
        {
            till=s[i]-'0';
        }
    else
        {
            till=9;
        }
    for(j=0;j<=till;j++)
    {
        ll newflag=flag;
        if(flag==0 && j<till)
            newflag=1;
        ll x=((abtakmod%m)+(j%m))%m;
        ans=(ans+(f(i+1,x,newflag)%hell))%hell;
    }
    dp[i][abtakmod][flag]=ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>s;
    cin>>m;
    n=s.size();
    cout<<(f(0,0,0)+hell-1)%hell;
    return 0;
}
