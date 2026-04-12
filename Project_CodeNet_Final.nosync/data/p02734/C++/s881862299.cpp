#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ordered_set tree < ll ,  null_type ,  less<ll> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//added two more functions to set
//(1)*(set.find_by_order(k))[kth element in the sorted set] 
//(2)set.order_of_key(k)[count of elements strictly less than k]
typedef vector< int > vi;
typedef vector< ll > lvi;
typedef vector< vi > vvi;
typedef vector< lvi > lvvi;
typedef pair< int,int > ii;
typedef pair< ll,ll > lii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)//remember i is an iterator
#define present(c,x) ((c).find(x) != (c).end())//for sets,maps,multimaps
#define cpresent(c,x) (find(all(c),x) != (c).end())//for vectors
#define tc(t) int (t); cin>>(t);while((t)--)
#define ff first
#define ss second
#define mp make_pair
#define ld long double
#define ull unsigned long long int
#define mod 998244353
ll ans=0,dp[3001][3001],n,s,a[4000];
ll recurs(int idx,int s1)
{
	if(s1==0) return (n-idx+1);
	if(idx>=n) return 0; 
	if(s1<0) return 0;
	if(dp[idx][s1]!=-1) return dp[idx][s1];
	ll val1=recurs(idx+1,s1);
	ll val2=recurs(idx+1,s1-a[idx]);
	if(s==s1)
	{
		// cout<<idx<<" "<<val2<<endl;
		ans=(ans+(val2*(idx+1))%mod)%mod;
	}
	dp[idx][s1]=(val1+val2)%mod;
	// cout<<
	return dp[idx][s1];
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	recurs(0,s);
	cout<<ans<<endl;
	return 0;
}