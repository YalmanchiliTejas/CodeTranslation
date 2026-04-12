#include "iostream"
using namespace std;
int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ans += 800;
		if (i % 15 == 0)ans -= 200;
	}
	cout << ans << endl;
	return 0;
}