#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	int ma = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int H; cin >> H;
		ma = max(ma, H);
		ans += (ma == H);
	}
	cout << ans << '\n';

	return 0;
}
