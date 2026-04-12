#include<bits/stdc++.h>
using namespace std;
 
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
typedef tree<int, null_type,
		less_equal<int>, 
		rb_tree_tag,tree_order_statistics_node_update> ordered_mset;
		
typedef tree<int, null_type,
		less<int>, 
		rb_tree_tag,tree_order_statistics_node_update> ordered_set;
*/
 
/*
 
PBDS
-------------------------------------------------
			0 based indexing
-------------------------------------------------			 
1) insert(value)
2) erase(value)
3) order_of_key(value) // Number of items strictly smaller than value
4) *find_by_order(k) : K-th element in a set (counting from zero)
 
*/
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());	

int n;
ll ara[3005];
ll dp[3005][3005][2];
bool flag[3005][3005][2];

ll f(int i,int j,int move)
{
	if(i>j) return 0;
	
	if(flag[i][j][move]) return dp[i][j][move];
	
	if(move)
	{
		ll a=f(i+1,j,move^1)-ara[i];
		ll b=f(i,j-1,move^1)-ara[j];
		
		flag[i][j][move]=1;
		return dp[i][j][move]=min(a,b);
	}
	
	else
	{
		ll a=f(i+1,j,move^1)+ara[i];
		ll b=f(i,j-1,move^1)+ara[j];
		
		flag[i][j][move]=1;
		return dp[i][j][move]=max(a,b);
	}
	
}

void solve()
{
	cin>>n;
	
	for(int i=0;i<n;i++) cin>>ara[i];
	
	cout<<f(0,n-1,0);
}
	
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	solve();
	
	cerr<<"\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms\n";
	
	return 0;
}
