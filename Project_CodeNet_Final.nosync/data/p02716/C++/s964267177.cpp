#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int 		long long
#define vi 			vector<int>
#define vec(x) 		vector<x>
#define matrix 		vector<vector<int>>
#define pii 		pair<int,int>
#define repf(i,s,e)  for(int i=s;i<e;i++)
#define repb(i,e,s) for(int i=e;i>=s;i--)
#define MOD			1000000007
#define pb 			push_back
#define ff 			first
#define ss 			second
#define w(x)		int x; cin>>x; while(x--)
const int INF = 1e18;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order(k-1)  returns iterator to kth element starting from 0; Returns the kth smallest element
// order_of_key(k) returns count of elements strictly smaller than k;Returns the number of elements less than k
// erase,insert same as normal set


void solve() {
	int n;
	cin>>n;;

	vector<int> arr(n+1);
	repf(i,1,n+1){
		cin>>arr[i];
	}

	vector<vector<int>> dp(n+1,vector<int>(2,0));
	// dp[i][1]->max sum when we pick the ith element
	// dp[i][0]->max sum when we didn't pick the ith element

	dp[2][0]=arr[1],dp[2][1]=arr[2];
	for(int i=3;i<=n;i++){
		if(i&1){
			dp[i][1]=arr[i]+max({dp[i-3][1],dp[i-3][0],dp[i-2][0],dp[i-2][1]});
			dp[i][0]=max({arr[i-1]+dp[i-2][0],arr[i-2]+dp[i-3][0],arr[i-1]+dp[i-3][1],arr[i-1]+dp[i-3][0]});
		}
		else{
			dp[i][1]=arr[i]+max({dp[i-1][0],dp[i-2][1],dp[i-2][0]});
			dp[i][0]=arr[i-1]+dp[i-2][0];
		}
	}

	cout<<max(dp[n][0],dp[n][1])<<endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin),
		        freopen("output.txt", "w", stdout);
	}

	int t = 1;
	//cin>>t;
	while (t--) {
		solve();
	}
}