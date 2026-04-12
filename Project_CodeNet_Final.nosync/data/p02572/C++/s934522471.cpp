#include <bits/stdc++.h>
using namespace std;



//“Remember, Hope is a good thing, maybe the best of things, and no good thing ever dies.”

//― Stephen King


#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define in insert
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define si set<int>
#define mpii map<int, int>
#define prq priority_queue
#define sz(s) (int) s.size()
#define pf(a) printf("%d ",a)
#define si1(a) scanf("%d",&a)
#define si2(a,b) scanf("%d%d",&a,&b)
#define si3(a,b,c) scanf("%d%d%d",&a,&b,&c)
//#define scan(v) for(int i = 0; i<n; i++){int x;cin>>x;v.pb(x);}
#define pi 2 * acos (0.0)
#define inf 1e9
#define co cout
#define en '\n'
#define re return
#define con continue
#define dbg cout<<"___________ok____________"<<endl;
#define yes() printf("YES\n")
#define no() puts("NO\n")
#define FOR(i, j, k) for(int i=(j); i<(k); i++)
#define REV(i, j, k) for(int i=(n-1); i>=k; i--)
#define all(v) v.begin(), v.end()
#define unq(a) sort(all(a)), a.erase(unique(all(a)),a.end())
#define rnd(a, b) ((((rand()<<15)^rand())%((b)-(a) + 1))+(a))
#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL)
#define mem(x, y) memset(x, y, sizeof(x))
#define prn(v) for(auto x: v)cout<<x<<" ";
const double EPS = 1e-9;
const int MXX = 2e5 + 5;

ll MOD = 1e9 + 7;
ll a[MXX],cum[MXX];


ll power( ll a, ll p ) {
    ll res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x ); p >>= 1;
    }
    return res;
}
ll M  = MOD;
ll F(ll N,ll P)
{
	if(P==0)
    {
        return 1;
    }
	if(P%2==0)
	{
		ll ret=F(N,P/2);
		return ((ret%M)*(ret%M))%M;
	}
	else return ((N%M)*(F(N,P-1)%M))%M;

}
int main ()
{
    FAST_IO;
    ll n;cin>>n;
    FOR(i, 0, n)cin>>a[i];
    cum[0] = a[0];
    FOR(i, 1, n)cum[i] = cum[i-1]+a[i], cum[i]%=MOD;
    ll ans = 0;
    FOR(i, 0, n)
    {
        ll val = (cum[n-1]-cum[i])*a[i];
        ans = (ans + val)%MOD;
    }
    ans+=MOD;
    co<<ans%MOD<<en;
    return 0;
}
