#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fastio() ios_base::sync_with_stdio(false);
#define rmod(x, y) ((((x)%(y))+(y))%(y))
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T, typename R = null_type, typename C = less<T>>
tree<T, R, C, rb_tree_tag, tree_order_statistics_node_update> ordered_set(){
	return tree<T, R, C, rb_tree_tag, tree_order_statistics_node_update>();
}

const int maxn = 3005;
int n;
ll a[maxn], dp[maxn][maxn][2];

int main(){
	scanf("%d", &n);
	for(int i = 1; i<=n; i++) scanf("%lld", &a[i]), dp[i][i][0] = -(dp[i][i][1] = a[i]);
	for(int w = 1; w<n; w++){
		for(int i = 1; i+w <=n; i++){
			int r = i+w;
			dp[i][r][1] = max(dp[i+1][r][0]+a[i], dp[i][r-1][0]+a[r]);
			dp[i][r][0] = min(dp[i+1][r][1]-a[i], dp[i][r-1][1]-a[r]);
		}
	}
	printf("%lld\n", dp[1][n][1]);
	
	return 0;
}
