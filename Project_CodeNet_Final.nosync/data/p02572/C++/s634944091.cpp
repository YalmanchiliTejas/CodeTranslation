/*
    Author: Alam Khan
    AUST CSE 40th Batch

*/

#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
#define pb     push_back
#define inf     2e18
#define low     -2e18
#define PI        acos(-1.0)
#define endl  "\n"
#define FAST  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr freopen("input.txt","r",stdin)
#define fw freopen("output.txt","w",stdout)
const int sz = 2e5+9;
ll a[sz];
ll sum[sz];
ll N = 1e9+7;
ll mulMod(ll a,ll b,ll n)
{
    ll res = 0;
    a = a%n;
    while(b>0)
    {
        if(b%2==1)
        {
            res = (res+a)%n;
        }
        a = (a*2)%n;
        b/= 2;
    }
    return res;
}
int main()
{
    ll i,n,t,k,j,x=0,y=0,m;
    FAST
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        if(i==0)
            sum[i]  = a[i];
        else sum[i]  = a[i]+sum[i-1];
    }
    ll ans = 0;
    for(i=0;i<n-1;i++)
    {
        x = mulMod(a[i],(sum[n-1]-sum[i]),N);
        ans = (ans+x)%N;
    }
    cout<<ans<<endl;
    return 0;
}

