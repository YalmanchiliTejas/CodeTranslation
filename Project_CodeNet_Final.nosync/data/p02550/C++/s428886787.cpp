#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;

using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define N  100005

void solve()
{
    ll n,x,m;
    cin>>n>>x>>m;
    vi v;
    v.pb(x);
    map<ll,ll>lol;
    lol[x]=0;
    ll ind=-1,p;
    for(int i=2;i<=n;i++)
    {
        p=v.back();
        p=p*p;
        p%=m;
        if(p==0)
        {
            ll ans=0;
            for(auto u:v)
                ans+=u;
            cout<<ans<<endl;
            return;
        }
        if(lol.find(p)!=lol.end())
        {
            ind=lol[p];
            break;
        }
        v.pb(p);
        lol[p]=i-1;
    }
    if(ind==-1)
    {
        ll ans=0;
        for(auto u:v)
            ans+=u;
        cout<<ans<<endl;
        return;
    }
    ll sz=v.size();
    ll rsz=sz-ind;
    ll c=(n-ind)/rsz;
    ll rem=(n-ind)%rsz;
    ll ans=0;
    rep(i,0,sz)
    {
        if(i<ind)
            ans+=v[i];
        else
        {
            if(i-ind+1<=rem)
            {
                ans+=v[i]*(c+1);
            }
            else
                ans+=v[i]*c;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    time
    return 0;
}