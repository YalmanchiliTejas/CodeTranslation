#include"bits/stdc++.h"
#include<cassert>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 998244353;
const long long inf = 1ll << 61;
typedef pair<int, int> P;
int a[100006];
signed main() {
	int n; cin >> n;
	rep(i, n)cin >> a[i];
	int ans = 0;
	for (int c = 1; c < n-1; c++) {
		int sum = 0;
		for (int k = 0; c*k < n - 1; k++) {
			sum += a[k*c];
			sum += a[n - 1 - k*c];
			if ((n - 1) % c == 0 && (n - 1 - k*c) <= k*c)break;
			if (c >= n - 1 - k*c)break;
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
}