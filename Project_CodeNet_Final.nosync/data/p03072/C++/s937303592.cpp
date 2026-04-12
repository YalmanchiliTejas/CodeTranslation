#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, H, tmp, ans = 1;
	cin >> N >> tmp;
	for (int i = 1; i < N; ++i) {
		cin >> H;
		if (tmp <= H) ++ans;
		tmp = max(tmp, H);
	}
	cout << ans << endl;
}