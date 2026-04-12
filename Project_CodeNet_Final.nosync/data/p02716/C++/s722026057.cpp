#include <bits/stdc++.h>
 
#define ff first
#define ss second
#define mp make_pair
 
using namespace std;

typedef long long ll;

int v[200005];
bool mark[200005][5][2];
ll dp[200005][5][2];
int n,T;

ll f(int i, int j, bool has) {
	if(i == n) return j > 1 ? - 1e18 : 0;
	if(mark[i][j][has]) return dp[i][j][has];
	mark[i][j][has] = true;

	ll ret = - 1e18;

	if(has) {
		ret = max(ret, f(i+1, j, false) + v[i]);
		if(j) ret = max(ret, f(i+1, j-1, true));
	}
	else ret = max(ret, f(i+1, j, true));

	return dp[i][j][has] = ret;
}

int main(){
	scanf("%d", &n);

	ll ans = 0;
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	int space = (n%2 == 0) ? 1 : 2;
	printf("%lld\n", f(0, space, true));

	return 0;
}
