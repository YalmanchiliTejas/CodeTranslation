#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	ll ans = 0;
	if (a + b > 2 * c) {
		ans += (2 * c)*min(x, y);
		if (x > y) {
			if (2 * c < a) ans += (2 * c)*(x - y);
			else ans += a*(x - y);
			cout << ans << endl;
		}
		else {
			if (2 * c < b) ans += (2 * c)*(y - x);
			else ans += b*(y - x);
			cout << ans << endl;
		}
	}
	else {
		ans += a*x + b*y;
		cout << ans << endl;
	}
}