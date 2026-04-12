#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 100;

char N[MAXN + 2];

int main() {
	int K;
	cin >> N >> K;
	int n = strlen(N);
	if(n < K) {
		cout << 0 << '\n';
		return 0;
	}
	for(int i = 0; i < n; i++) N[i] -= '0';
	N[n] = 1;
	int ans = 0;
	if(K == 1) {
		ans += N[0];
		ans += (n - 1) * 9;
	} else if(K == 2) {
		int i = 1;
		while(!N[i]) i++;
		if(i < n) ans = N[i] + (n - 1 - i) * 9;
		ans += (N[0] - 1) * (n - 1) * 9;
		ans += (n - 1) * (n - 2) / 2 * 9 * 9;
	} else if(K == 3) {
		int i = 1, j;
		while(!N[i]) i++;
		if(i < n - 1) {
			j = i + 1;
			while(!N[j]) j++;
			if(j < n) {
				ans += N[j];
				ans += (n - 1 - j) * 9;
			}
			ans += (N[i] - 1) * (n - 1 - i) * 9;
			int k = n - 1 - i;
			ans += k * (k - 1) / 2 * 9 * 9;
		}
		ans += (N[0] - 1) * (n - 1) * (n - 2) / 2 * 9 * 9;
		ans += (n - 1) * (n - 2) * (n - 3) / 6 * 9 * 9 * 9;
	}
	cout << ans << '\n';
}
