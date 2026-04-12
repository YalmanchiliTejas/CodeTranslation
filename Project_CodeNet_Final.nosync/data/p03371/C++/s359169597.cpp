#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;++i)
#include<string>
using namespace std;
typedef long long ll;
//max=({});


int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if (a + b >= 2 * c) {
		if (x >= y) {
			if (a<=2*c) {
				int ans = 2 * y * c + a * (x - y);
				cout << ans << endl;
			}
			else {
				int ans = 2 * y * c + 2 * c * (x - y);
				cout << ans << endl;
			}
		}
		else {
			if (b<=2*c) {
				int ans = 2 * x * c + b * (y - x);
				cout << ans << endl;
			}
			else {
				int ans = 2 * x * c + 2 * c * (y - x);
				cout << ans << endl;
			}
		}
	}
	else {
		int ans = a * x + b * y;
		cout << ans << endl;
	}
	return 0;
}
