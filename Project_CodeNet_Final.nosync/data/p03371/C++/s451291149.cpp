#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	ll ans = 0;
	if( a + b >= 2 * c ) {
		if( x > y ) {
			ans += 2 * c * y;
			
			if( a <= 2 * c ) {
				ans += (x - y) * a;
			} else {
				ans += (x - y) * 2 * c;
			}
		} else if( x < y ) {
			ans += 2 * c * x;
			
			if( b <= 2 * c ) {
				ans += (y - x) * b;
			} else {
				ans += (y - x) * 2 * c;
			}
		} else {
			ans += 2 * c * x;
			cout << ans << endl;
			return 0;
		}
	} else {
		ans = a * x + b * y;
	}
	
	cout << ans << endl;
	
	return 0;
}
