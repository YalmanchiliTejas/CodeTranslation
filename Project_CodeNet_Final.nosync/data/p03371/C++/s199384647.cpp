#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = 1001001001;
	if(x > y) {
		swap(x, y); // x <= y
		swap(a, b);
	}
	int t = a * x + b * y;
	ans = min(ans, t);
	t = 2 * c * x + b * (y-x);
	ans = min(ans, t);
	t = 2 * c * y;
	ans = min(ans, t);
	cout << ans << endl;
	
	return 0;
}