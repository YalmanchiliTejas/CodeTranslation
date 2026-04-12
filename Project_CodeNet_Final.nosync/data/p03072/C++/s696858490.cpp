#include <bits/stdc++.h>
using namespace std;
#define int long long
#define END getchar();getchar();return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1000000007
typedef pair<int, int> P;

bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}

signed main() {
	int n, ma = 0, ans = 0;
	cin >> n;
	rep(i, n) {
		int t;
		cin >> t;
		if (t >= ma) {
			ans++;
		}
		ma = max(ma, t);
	}
	cout << ans << endl;

	END;
}
