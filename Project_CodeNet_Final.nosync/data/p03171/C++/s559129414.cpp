#include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
// using namespace __gnu_pbds;
typedef long double ld;
typedef long long ll;
#define int ll
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define vi vector<int>
#define pii pair<int,int>
#define For(i,s,e) for (ll i=(s); i<(e); i++)
#define MAX 3003
#define initialize(arr,elem) memset(arr,elem,sizeof(arr))
#define sz size
const int MOD = 1e9+7;

// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int n, arr[MAX], dp[MAX][MAX][2],visited[MAX][MAX][2];

int solve(int i, int j, int turn){
	if (i>j) return 0;
	if (i==j && turn){
		visited[i][j][turn] = 1;
		return dp[i][j][turn] = arr[i];
	}
	if (i==j && !turn){
		visited[i][j][turn] = 1;
		return dp[i][j][turn] = -arr[i];
	}
	if (visited[i][j][turn] !=-1) return dp[i][j][turn];

	if (turn){
		dp[i][j][turn] = max(arr[i] + solve(i+1,j,turn^1),arr[j] + solve(i,j-1,turn^1));
	} 
	else{
		dp[i][j][turn] = min(solve(i+1,j,turn^1)-arr[i],solve(i,j-1,turn^1)-arr[j]);
	}
	visited[i][j][turn] = 1;
	return dp[i][j][turn];
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		


	cin>>n;
	For(i,1,n+1) cin>>arr[i];
	initialize(visited,-1);
	initialize(dp,0);
	cout<<solve(1,n,1)<<endl;
	return 0;
}
