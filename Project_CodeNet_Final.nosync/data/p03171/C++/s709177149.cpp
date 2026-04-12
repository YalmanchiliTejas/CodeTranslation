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
bool vis[maxn][maxn][2];
int n;
ll a[maxn], dp[maxn][maxn][2], pre[maxn];

inline ll get(int l, int r){return pre[r]-pre[l-1];}

ll solve(int l, int r, bool taro){
	if (l == r) {
		if (taro) return a[l];
		return -a[l];
	}
	ll &ret = dp[l][r][taro];
	if(vis[l][r][taro]) return ret;
	if (taro) ret = max(a[l]+solve(l+1, r, 0), a[r]+solve(l, r-1, 0));
	else ret = min(solve(l+1, r, 1)-a[l], solve(l,r-1, 1)-a[r]);
	vis[l][r][taro] = 1;
	return ret;
}


int main(){
	
	scanf("%d", &n);
	for(int i = 1; i<=n; i++) scanf("%lld", &a[i]), pre[i] = a[i]+pre[i-1];
	printf("%lld\n", solve(1, n, 1));
	return 0;
}
