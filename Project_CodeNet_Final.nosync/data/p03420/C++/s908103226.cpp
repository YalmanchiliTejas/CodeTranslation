#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 1<<18, rt = 1<<10;
ll count(int n, int k, int a) {
	int l = n-a+1;
	int m = l + (a - l%a)%a;
	int r = n-k+1;
	m = min(r, m);
	return max(0, m-l)*1ll*(l/a + 1) + max(0, r-m)*1ll*(m/a + 1);
}
int solve() {
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans += count(n, k, i);
	if(k == 0) ans -= n;
	cout << ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	solve();
}
