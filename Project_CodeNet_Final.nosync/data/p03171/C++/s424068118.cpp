#include <bits/stdc++.h>
using namespace std;

int n;
int a[3005];
long long dp[3005][3005];
const long long MN = 1e15;
long long f(int l, int r, bool turn){
	if (l == r) return turn ? a[l] : -a[l];
	long long &ret = dp[l][r];
	if (ret != -MN) return ret;
	if (turn){
		ret = max(ret, f(l+1, r, turn^1) + a[l]);
		ret = max(ret, f(l, r-1, turn^1) + a[r]);
	} else {
		ret = MN;
		ret = min(ret, f(l+1, r, turn^1) - a[l]);
		ret = min(ret, f(l, r-1, turn^1) - a[r]);
	}
	//cout << l << ' ' << r << " : " << turn << " _ " << ret << '\n';
	return ret;
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		dp[i][j] = -MN;
	cout << f(1, n, 1) << '\n';
	return 0;
}
