#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define f first
#define s second
#define mp make_pair
#define sz size()
#define ll long long
int n;
bool was[3010][3010];
ll dp[3010][3010];
int a[3010];
ll calc(int l, int r) {
	if(l > r) return 0;
	if(l == r) return a[r];
	if(was[l][r]) return dp[l][r];
	was[l][r] = 1;
	dp[l][r] = max(a[l] - calc(l + 1, r), a[r] - calc(l, r - 1)); // max(áåð¸ì ïåðâûé, áåð¸ì ïîñë.)
//	cout << "podotrezok " << l << ' ' << r << " answer is " << dp[l][r] << '\n';
	return dp[l][r];
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", a + i);
	ll ans = calc(1, n);
	printf("%lld", ans);
	return 0;
}