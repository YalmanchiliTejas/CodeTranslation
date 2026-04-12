#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	int mx = 0, ans = 0;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (mx <= x) ++ans;
		mx = max(mx, x);
	}
	cout << ans << endl;
	return 0;
}