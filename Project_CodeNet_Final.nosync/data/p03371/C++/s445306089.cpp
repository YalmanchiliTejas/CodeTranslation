#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
	ll A, B, C, X, Y;
	ll ans = 0;
	vector<ll> v;

	cin >> A >> B >> C >> X >> Y;

	v.push_back(max(X, Y)*C * 2);
	v.push_back(X*A + Y * B);
	if (X > Y) {
		ll sa = X - Y;
		v.push_back(sa*C * 2 + Y * B + A * X);
		v.push_back(A*sa + 2 * C * Y);

		//cout << "sa" <<  X  << endl;
	}
	else {
		ll sa = Y - X;
		v.push_back(sa*C * 2 + X * A + B * Y);
		v.push_back(B*sa + 2 * C*X);
	}

	/*for (auto it = v.begin();it != v.end();it++) {
		cout << "aa" << *it << endl;
	}*/

	cout << *min_element(v.begin(), v.end()) << endl;

	return 0;
}