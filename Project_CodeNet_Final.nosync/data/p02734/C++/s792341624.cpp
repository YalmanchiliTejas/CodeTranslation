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

const int maxn = 3005, mod = 998244353;
int n, S, a[maxn], dp[maxn][maxn][3];

/*
k = 0: before starting L
k = 1: currently in [L, R]
k = 2: finished [L, R]
*/

void add(int &x, int y){ y%=mod, x+=y, x%=mod;}

int main(){
	scanf("%d %d", &n, &S);
	for(int i = 1; i<=n; i++) scanf("%d", &a[i]);
	dp[0][0][0] = 1;
	for(int i = 1; i<=n; i++){
		for(int s = 0; s<=S; s++){
			add(dp[i][s][0], dp[i-1][s][0]);
			add(dp[i][s][1], dp[i-1][s][1] + dp[i-1][s][0]);
			add(dp[i][s][2], dp[i-1][s][2] + dp[i][s][1]);
			if (s>=a[i]){
				add(dp[i][s][1], dp[i-1][s-a[i]][0]+dp[i-1][s-a[i]][1]);
				add(dp[i][s][2], dp[i-1][s-a[i]][0]+dp[i-1][s-a[i]][1]);
			}
		}
	}
	printf("%d\n", dp[n][S][2]);
	return 0;
}
