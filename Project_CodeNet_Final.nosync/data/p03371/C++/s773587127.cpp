#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {        
	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if (a + b <= 2 * c) {
		cout << 1LL * a * x + 1LL * y * b;
	}else {
		ll ans = min(x,y) * 2 * c;
		if (x < y) {
			if (b <= 2 * c) {
				ans += (y - x) * b;
			}else {
				ans += (y - x) * 2 * c;
			}
		}else {
			if (a <= 2 * c) {
				ans += (x - y) * a;
			}else {
				ans += (x - y) * 2 * c;
			}	
		}
		cout << ans;
	}
}






