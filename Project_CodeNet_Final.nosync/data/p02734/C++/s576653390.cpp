#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
 
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
#define int ll
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second

typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int MAX = 3003, MOD = 998244353;
int dp[MAX][MAX], arr[MAX], n,s;


signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>s;
	for(int i=1;i<=n;i++) cin>>arr[i];
	int ans = 0;
	for(int i=1;i<=n;i++){
		dp[i][arr[i]] = i;

		for(int j=0; j+arr[i]<=s;j++){
			dp[i][j+arr[i]] += dp[i-1][j];
			dp[i][j+arr[i]] %= MOD;
		}
		ans = (ans + (n-i+1)*dp[i][s]) %MOD;
		for(int j=0;j<=s;j++) dp[i][j] = (dp[i][j] + dp[i-1][j]) %MOD;
	}
	cout<<ans;
	

	return 0;
}