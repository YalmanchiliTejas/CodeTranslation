/*input
4
10 80 90 30
*/
/*

**************************
*						 *
* AUTHOR :: knight_coder *
*						 *
**************************

*/
#include<bits/stdc++.h>
#define lld          long long int
#define pb          push_back
#define ppb         pop_back
#define	endl		'\n'
#define mii         map<lld,lld>
#define msi         map<string,lld>
#define mis         map<lld, string>
#define mpi         map<pair<lld ,lld >,lld >
#define pii         pair<lld,lld>
#define vi          vector<lld>
#define vpi 		vector<pii>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (lld)x.size()
#define hell        1000000007
#define rrep(i,m,n)	for(lld i=m;i>=n;i--)
#define rep(i,m,n)	for(lld i=m;i<n;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define what_is(x)  cerr << #x << " is " << x << endl;
#define pr(x) 		cout<< x << " ";
#define pre(x)		cout<< x << endl ;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// template<typename T>
// using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>; 
//change null_type to get ordered_map
using namespace std;
#define N  3005
lld dp[N][N];
void inii()
{
	rep(i,0,N)
	{
		rep(j,0,N)
		{
			dp[i][j]=-1;
		}
	}
}
lld a[N];
lld solve2(lld pos,lld pos2)
{
	if(pos==pos2)
	{
		return a[pos];
	}
	if(pos2<pos)
	{
		return 1e10;
	}
	if(dp[pos][pos2]!=-1)
	{
		return dp[pos][pos2];
	}
	lld mx=0;
	mx=max(a[pos]-solve2(pos+1,pos2),a[pos2]-solve2(pos,pos2-1));
	// cout << solve2(pos+1,pos2) << ' ' << solve2(pos,pos2-1) << ' ' << pos <<' ' << pos2<<endl; 
	return dp[pos][pos2]=mx;
}
void solve()
{
	lld n;
	cin >> n;
	inii();
	rep(i,0,n)
	{
		cin >> a[i];
	} 
	cout << solve2(0,n-1) << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tests=1;
	//cin>>tests;
	while(tests--)
	{
		solve();
	}
}