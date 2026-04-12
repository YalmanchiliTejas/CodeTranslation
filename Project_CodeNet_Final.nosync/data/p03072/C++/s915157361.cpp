#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	int ans = 0;
	int res = h[0];
	rep(i, n) {
		if (res <= h[i])ans++;
		res = max(res, h[i]);
	}
	cout << ans << endl;
}