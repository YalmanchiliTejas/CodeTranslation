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
const int MOD = 998244353;

const bool DEBUG = 0;
const int MAXN = 3005;

int n;
ll a[MAXN];
ll dp[MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin>>n;
	forn(i,0,n) cin>>a[i];
	
	forn(i,0,n) forn(j,i,n) dp[i][j]=-INF;
	
	for(int l=n-1;l>=0;l--) forn(r,l,n)
	{
		dp[l][r]=max(dp[l][r], a[l]+min(dp[l+2][r]-(l<r?a[l+1]:0), dp[l+1][r-1]-(l<r?a[r]:0))); //take left
		dp[l][r]=max(dp[l][r], a[r]+min(dp[l+1][r-1]-(l<r?a[l]:0), dp[l][r-2]-(l<r?a[r-1]:0))); //take right
	}
	
	cout<<dp[0][n-1]<<'\n';
	
	return 0;
}
