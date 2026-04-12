#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

#define ll long long
#define int long long
#define double long double

#define all(a)      (a).begin(),(a).end()
#define sz(x)       (int)x.size()

#define ff first
#define ss second
#define mp make_pair

#define pb push_back
#define endl "\n"

#define bp builtin_popcountll
#define inf 1e18

const int N=1e5+5;
const int M=1e9+7;

void solve()
{
    ll n,x,mod;
    cin >> n >> x >> mod;
    if(n<=2e6)
    {
        ll ans = 0;
        while(n--)
        {
            ans = ans + x;
            x = (x*x)%mod;
        }
        cout<<ans<<"\n";
        return;
    }
    ll ans = 0;
    map<ll,ll> y;
    ll temp = x;
    vector<ll> pre;
    pre.pb(0);
    ll start = -1,end = -1,sz=-1;
    for(ll i=1;;i++)
    {
        ll rem = temp % mod;
        pre.pb(temp);
        if(y.find(rem)!=y.end())   
        {
            start = y[rem];
            end = i-1;
            sz = end - start + 1;
            break;
        } 
        y[rem] = i;
        temp = temp*temp;
        temp %= mod;
    }
    for(ll i=1;i<pre.size();i++)   pre[i] += pre[i-1];
    n -= (start - 1);
    ans += pre[start-1];
    ans += (n/sz)*(pre[end] - pre[start-1]);
    n = n % sz;
    ll i = start;
    while(n--)    ans += pre[i] - pre[i-1],i++;
    cout<<ans;
}

signed main()
{
    FAST

    int t=1;
    // cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        // cout<<"Case #"<<tc<<": ";
        solve();
    }

}