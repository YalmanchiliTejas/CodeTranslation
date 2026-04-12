#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main() {
	ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

	ll ans = numeric_limits<ll>::max();

	ans = min(ans, X*A + Y*B);

	if(X>Y) {
		ans = min(ans, Y*C*2 + (X-Y)*A);
	} else {
		ans = min(ans, X*C*2 + (Y-X)*B);
	}

	ans = min(ans, C * max(X,Y) * 2);

	cout << ans << endl;
}
