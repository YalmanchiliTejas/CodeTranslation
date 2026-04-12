#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int a[100010]; 
int main() {
	int n;
	cin >> n;
	rep(i,n) cin >> a[i];
	sort(a,a+n);
	ll ans = a[n-1] - a[0];
	for (int i = 1; i < n/2; i++)
	{
		ans += a[n-i] - a[i];
		ans += a[n-i-1] - a[i-1];
	}
	if (n % 2 == 1) {
		ans += max(a[n/2+1]-a[n/2],a[n/2]-a[n/2-1]);
	}
	cout << ans << endl;
	return 0;
}