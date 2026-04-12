#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define mp make_pair
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
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
ll dp[3005][3005];
ll n,k,l;
ll a[3005];
ll solve(ll i,ll j)
{
    if(i==j)
    {
        if(n%2)
            return a[i];
        else
            return -a[i];
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll x;
    x=n-j+i-1;
    ll p;
    ll b=x%2;
    ll c;
    if(b)
        c=-1;
    else
        c=1;
    if(b)
        p=min((c*a[i]+solve(i+1,j)),(c*a[j]+solve(i,j-1)));
    else
        p=max((c*a[i]+solve(i+1,j)),(c*a[j]+solve(i,j-1)));
    /*if(b)
    {
        p=p*(-1);
    }*/
    dp[i][j]=p;
    return p;
}
/*ll dp[100005];a
ll n,i,j,K;
ll a[105];
set<ll> s;
ll solve(ll k)
{
    if(k<0)
        return -1;
    if(k==0)
        return 0;
    if((s.find(k))!=(s.end()))
        return 1;
    if(dp[k]!=-1)
        return dp[k];
    ll f=0;
    ll x=1;
    for(i=1;i<=n;i++)
    {
        x=1+solve(k-a[i]);
        if((x%2)==1)
            f=1;
    }
    dp[k]=f;
    return f;
}*/

int main()
{
    for(k=0;k<3005;k++)
        for(l=0;l<3005;l++)
            dp[k][l]=-1;
    /*for(i=0;i<100005;i++)
            dp[i]=-1;
    cin>>n>>K;
    for(i=1;i<=n;i++)
        {cin>>a[i];
        s.insert(a[i]);
        }
    ll ppp=solve(K);
    if(ppp)
        cout<<"First";
    else
        cout<<"Second";*/
    cin>>n;
    for(k=0;k<n;k++)
        cin>>a[k];
    cout<<solve(0,n-1);
    return 0;
}




