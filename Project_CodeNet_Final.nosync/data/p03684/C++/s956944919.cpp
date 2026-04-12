#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size() 

ll parent[500005],s[500005];
 
ll Root(ll i)
{
    if(parent[parent[i]]!=parent[i])
        parent[i]=Root(parent[i]);
    return parent[i];
}
void Uni(ll a,ll b)
{
    ll parent_a=Root(a),parent_b=Root(b);
    if(parent_a==parent_b)
        return;
    if(s[parent_a]>=s[parent_b])
    {
         s[parent_a]+=s[parent_b];
         parent[parent_b]=parent_a;
    }
    else
    {
         s[parent_b]+=s[parent_a];
         parent[parent_a]=parent_b;
    }
    return;
} 

int main()
{
    ios_base::sync_with_stdio(false);
    ll n,i,j,k,x,y,t,m;

    cin >> n ;
    vector<pll>v,X,Y;
    vector< pair< ll , pll > >e;

    for(i=1;i<=n;i++)
    {
        cin >> x >> y;
        v.pb({x,y});
        X.pb({x,i});
        Y.pb({y,i});
    }

    sort(all(X)),sort(all(Y));

    for(i=1;i<=n;i++)
        s[i]=1,parent[i]=i;


    for(i=0;i<sz(X);i++)
    {
        if(i+1<sz(X))
            e.pb({X[i+1].ff-X[i].ff,{X[i].ss,X[i+1].ss}});
        if(i-1>=0)
            e.pb({X[i].ff-X[i-1].ff,{X[i-1].ss,X[i].ss}});
    }
    for(i=0;i<sz(Y);i++)
    {
        if(i+1<sz(Y))
            e.pb({Y[i+1].ff-Y[i].ff,{Y[i].ss,Y[i+1].ss}});
        if(i-1>=0)
            e.pb({Y[i].ff-Y[i-1].ff,{Y[i-1].ss,Y[i].ss}});
    }

    sort(all(e));
    ll ans=0,tot=0;
    for(i=0;i<sz(e);i++)
    {
        if(tot==n-1)
            break;
        else
        {
            x=e[i].ss.ff,y=e[i].ss.ss;
            if(Root(x)==Root(y))
                continue;
            else
            {
                Uni(x,y);
                ans+=e[i].ff;
                tot++;
            }
        }
    }
    cout<<ans<<endl;
}