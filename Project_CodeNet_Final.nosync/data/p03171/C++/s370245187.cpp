#include<bits/stdc++.h>

#define watch(x) cout << (#x) << " = " << x << endl;
#define mkp make_pair
#define mkt make_tuple
#define pb push_back
#define ll long long
#define ld long double
#define x first
#define y second

using namespace std;

pair<ll, ll> memo[3010][3010];
int n, a[3010];

pair<ll, ll> dp(int i, int j){
	if(i + j == n) return mkp(0, 0);
	pair<ll, ll>& ret = memo[i][j];

	if(ret.x != -1) return ret;

	if((i + j) & 1){
		//X - Y minimised

		if(dp(i + 1, j).x - a[i] - dp(i + 1, j).y < dp(i, j + 1).x - a[n - 1 - j] - dp(i, j + 1).y){
			ret = mkp(dp(i + 1, j).x, dp(i + 1, j).y + a[i]);
		} else {
			ret = mkp(dp(i, j + 1).x, dp(i, j + 1).y + a[n - j - 1]);
		}
	} else {
		if(dp(i + 1, j).x + a[i] - dp(i + 1, j).y > dp(i, j + 1).x + a[n - 1 - j] - dp(i, j + 1).y){
			ret = mkp(dp(i + 1, j).x + a[i], dp(i + 1, j).y);
		} else {
			ret = mkp(dp(i, j + 1).x + a[n - j - 1], dp(i, j + 1).y);
		}
	}

	return ret;
}

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			memo[i][j] = mkp(-1, -1);
		}
	}

	pair<ll, ll> ans = dp(0, 0);

	printf("%lld\n", ans.x - ans.y);

	return 0;
}