#include <bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
int a, b, c, x, y;
int main() {
	cin >> a >> b >> c >> x >> y;
	int res = 1e9;
	for(int i=0; i<=max(x, y); i++) {
		res = min(res, 2 * c * i + max(0, x - i) * a + max(0, y - i) * b);
	}
	cout << res;
	return 0;
}