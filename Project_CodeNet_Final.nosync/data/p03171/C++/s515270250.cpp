#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define debug(x) cerr<<#x<<" -> "<<x<<'\n'
#define debug2(x,y) cerr<<#x<<" -> "<<x<<" "<<#y<<" -> "<<y<<'\n'
#define debug3(x,y,z) cerr<<#x<<" -> "<<x<<" "<<#y<<" -> "<<y<<" "<<#z<<" -> "<<z<<'\n'

 
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

using ordered_set = tree<ll , null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
struct CMP {
	bool operator() (const T& lhs, const T& rhs) const{
		return lhs < rhs;
	}
};

template <typename T>
T power(T a, T n){
	T res = 1;
	while(n > 0){
		if(n & 1) res = (res * a);
		a = (a * a);
		n >>= 1;
	}
	
	return res;
}

template <typename T>
T power(T a, T n, long long mm){
	T res = 1;
	while(n > 0){
		if(n & 1) res = (res * a) % mm;
		a = (a * a) % mm;
		n >>= 1;
	}
	
	return res;
}

const ll N = 3e3+7;
const ll MOD = 1e9+7;
const ll INF = 2e14+7;

ll arr[N];
ll dp[N][N][2];

ll solve(int i, int j, int turn){
	if(i > j){
		return 0;
	}
	
	if(dp[i][j][turn] != -1) return dp[i][j][turn];
	
	if(turn == 0){
		return dp[i][j][turn] = max(arr[i] + solve(i + 1, j, 1), arr[j] + solve(i, j - 1, 1));
	}
	
	return dp[i][j][turn] = min(solve(i + 1, j, 0) - arr[i], solve(i, j - 1, 0) - arr[j]);
	
}

void testcase(){
	
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	memset(dp, -1, sizeof(dp));
	ll ans = solve(0, n - 1, 0);
	
	cout<<ans<<'\n';
	
}

signed main(){
	fast;
	
	int t = 1;
	//cin>>t;
	while(t--){
		testcase();
	}
	
	return 0;
}
