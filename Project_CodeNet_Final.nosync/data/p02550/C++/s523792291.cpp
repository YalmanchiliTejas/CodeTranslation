#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define watch(x) cout<<(#x)<<"="<<(x)<<'\n'
#define mset(d,val) memset(d,val,sizeof(d))
#define setp(x) cout<<fixed<<setprecision(x)
#define forn(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define F first
#define S second
#define pqueue priority_queue
#define fbo find_by_order
#define ook order_of_key
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void amin(ll &a, ll b){ a=min(a,b); }
void amax(ll &a, ll b){ a=max(a,b); }
void YES(){cout<<"YES\n";} void NO(){cout<<"NO\n";}
void SD(int t=0){ cout<<"PASSED "<<t<<endl; }
const ll INF = ll(1e18);
int MOD = 998244353;

ll add(ll a, ll b)
{
	a+=b; a%=MOD;
	if(a<0) a+=MOD;
	return a;
}
ll mult(ll a, ll b)
{
	if(a>MOD) a%=MOD;
	if(b>MOD) b%=MOD;
	ll ans=(a*b)%MOD;
	if(ans<0) ans+=MOD;
	return ans;
}
ll pw(ll a, ll b)
{
	ll r=1;
	while(b){
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}

const bool DEBUG = 0;
const int MAXN = 100005;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll n,X; cin>>n>>X>>MOD;
	set<ll> s;
	vi v;
	while(s.find(X)==s.end())
	{
		v.pb(X);
		s.insert(X);
		X=pw(X,2);
	}
	
	ll ans=0;
	reverse(v.begin(), v.end());
	while(v.back()!=X)
	{
		ans+=v.back();
		v.pop_back(); n--;
		if(n==0)
		{
			cout<<ans<<'\n';
			return 0;
		}
	}
	reverse(v.begin(), v.end());
	
	ll sum=0;
	for(ll x: v) sum+=x;
	
	forn(i,0,n%v.size()) ans+=v[i];
	ans+=sum*(n/v.size());
	cout<<ans<<'\n';
	
	return 0;
}
