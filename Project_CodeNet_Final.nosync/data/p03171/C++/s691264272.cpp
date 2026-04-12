// #include <boost/multiprecision/cpp_int.hpp> 
// using namespace boost::multiprecision; 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<b ; i++)
#define mp make_pair
#define INF 1000000000000000000
#define mod 1000000007
#define pi pair<ll,ll>
#define pd pair<ld,ld>
#define vi vector<ll>
#define vd vector<ld>
#define vvi vector<vi>
#define vvd vector<vd>
#define vpi vector<pi>
#define vpd vector<pd>
#define us unordered_set<ll>
#define um unordered_map<ll,ll>
#define sortA(a) sort(a.begin(),a.end())
#define sortD(a) sort(a.begin(),a.end(),greater<ll>())
#define all(a) a.begin(),a.end()
#define N 100005


#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> new_data_set; 
#define in insert
#define fbo find_by_order
#define ook order_of_key


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

ll powmod(ll x,ll y)
{
	if(x==0)
		return 0;
	if(y==0 || x==1)
		return 1;
	if(y%2==0)
		return powmod((x*x)%mod,y/2)%mod;
	return (x*powmod(x,y-1)%mod)%mod;
}
void print1D(vi a)
{
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void print2D(vector<vi> a)
{
	for(ll i=0;i<a.size();++i)
	{
		for(ll j=0;j<a[i].size();++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
void solve()
{
	ll n;
	cin>>n;
	vi a(n+1);
	for(ll i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	vvi dp(n+2,vi(n+2));
	for(ll i=1;i<=n;++i)
	{
		dp[i][i]=a[i];
	}
	for(ll l=2;l<=n;++l)
	{
		for(ll i=1;i<=n-l+1;++i)
		{
			ll j=i+l-1;
			ll x=min(dp[i+2][j]+a[i]-a[i+1],dp[i+1][j-1]+a[i]-a[j]);
			ll y=min(dp[i][j-2]+a[j]-a[j-1],dp[i+1][j-1]+a[j]-a[i]);
			dp[i][j]=max(x,y);
			// debug(i,j,dp[i][j]);
		}
	}
	cout<<dp[1][n]<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--)
	{
		solve();
	}
}
