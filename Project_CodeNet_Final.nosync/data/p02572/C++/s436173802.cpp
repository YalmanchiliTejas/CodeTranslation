#include <algorithm>
#include <iostream>

using namespace std;

const int MD = 1000000007;

int main() {
	int n; cin >> n;
	int x = 0, ans = 0;
	while (n--) {
		int a; cin >> a;
		ans = (ans + (long long) x * a % MD) % MD;
		x = (x + a) % MD;
	}
	cout << ans << '\n';
	return 0;
}
