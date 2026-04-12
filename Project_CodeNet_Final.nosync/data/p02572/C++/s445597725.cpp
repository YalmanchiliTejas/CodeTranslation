#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;

#define pll pair<ll,ll>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define rep(i,n) for (int i = 0; i < n; ++i) 
#define REP(i,k,n) for (int i = k; i <= n; ++i) 
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sz(a) int((a).size())
#define endl '\n' // remove for interactive

const int INF = 1e9;
const ll mod = 1e9 + 7;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

int diff(string a, string b)
{
    int ret = 0;
    int n = a.size();
    for(int i = 0; i < n; i++)
    {
        if(a[i] != b[i]) ret++;
    }
    return ret;
}

void solve()
{
    int n; cin>>n;
    vi v;
    // ll sm = 0;
    vl sm(n+3);
    rep(i, n)
    {
        int x; cin>>x;
        v.pb(x);
        // sm += x;
    }
    REPR(i, n-1, 0)
    {
        sm[i] = (sm[i+1] + v[i+1]) % mod;
    }
    ll ans = 0;
    rep(i, n) {
        ll put = (1LL*v[i]*(sm[i])) % mod;
        ans = (ans + put) % mod;
    }
    cout<<ans;
}

int main()
{
    // clock_t start, end;
    // start = clock();
    ios_base::sync_with_stdio(0); //cant use scanf, printf
    cin.tie(0);cout.tie(0); // no longer auto flush cout before each cin, remove for interactive
    int t = 1;
    // cin>>t;
    REP(i, 1, t)
    {
        solve();
        
    }
    // end = clock();
    // double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    // watch(time_taken);
    ll x = INF; x++;
    return 0;
    
}



/*before sub
TEST: 0(1 by 1 too), 1, equal, -ve, bounds(random and ez)
ERR/WA: loop vars, out of bounds, endl, finish taking inputs, large doubles, larger INF, corr mod, t, early/late mod
RE: double dec, integer overflow(ll or 1LL mult)
*/



