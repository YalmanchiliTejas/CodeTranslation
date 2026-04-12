#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <iomanip>
#include <vector>
#include <queue>
#include <functional>
#include <random>
#include <time.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
#define rep(i,n) for(ll i=0;i<(n);i++)
int main() {
	ll a, b, c, x, y;
	ll ans = 1e18;
	cin >> a >> b >> c >> x >> y;
	for (ll i = 0; i <= max(x, y) * 2; i += 2) {
		ll num = i * c + max(0ll, x - i / 2)*a + max(0ll, y - i / 2)*b;
		ans = min(ans, num);
	}
	cout << ans << endl;
	return 0;
}
