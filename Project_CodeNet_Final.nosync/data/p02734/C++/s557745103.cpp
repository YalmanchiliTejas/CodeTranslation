#include<bits/stdc++.h> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp> 
#define mod 1000000007
#define mod2 998244353
#define int long long
#define endl "\n"
#define p_b push_back
#define m_p make_pair
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
template <class T> 
using _ost = tree<
		T, 
		null_type, 
		less<T>, 
		rb_tree_tag, 
        tree_order_statistics_node_update>;

const int _M=3005;

int dp[_M][_M];
int pre[_M][_M];

int32_t main(){
 	fastIO;
 	
 	int n,s,ans;
 	cin >> n >> s;	
 	int a[n+1];
 	for(int i = 1; i <= n; i++)
 		cin >> a[i];
 	
 	for(int i = 1; i <= n; i++){
 		dp[i][a[i]] = i;

 		for(int j = a[i]+1; j < _M; j++){
 			dp[i][j] = pre[i-1][j-a[i]];
 		}

 		for(int j = 1; j < _M; j++){
 			pre[i][j] = pre[i-1][j] + dp[i][j];
 			pre[i][j] %= mod2;
 		}
 	}
 	
 	ans = 0;

 	for(int i = 1; i <= n; i++){
 		ans += (n-i+1)*dp[i][s];
 		ans %= mod2;
 	}
 	cout << ans << endl;
} 	