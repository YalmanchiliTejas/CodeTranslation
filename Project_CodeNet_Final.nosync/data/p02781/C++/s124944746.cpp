// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

int ch(int n, int k) {
	return n < k ? 0 : k == 0 ? 1 : ch(n - 1, k - 1) * n / k;
}

int power(int a, int k) {
	return k == 0 ? 1 : power(a, k - 1) * a;
}

int main() {
	string s; cin >> s;
	int n = s.length();
	int k; cin >> k;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int d = s[i] - '0';
		if (d)
			cnt++;
	}
	int ans = cnt == k;
	cnt = 0;
	for (int i = 0; i < n; i++) {
		int d = s[i] - '0';
		if (d == 0)
			continue;
		ans += ch(n - 1 - i, k - cnt) * power(9, k - cnt);
		if (k > cnt)
			ans += ch(n - 1 - i, k - cnt - 1) * power(9, k - cnt - 1) * (d - 1);
		if (cnt++ == k)
			break;
	}
	cout << ans << '\n';
	return 0;
}
