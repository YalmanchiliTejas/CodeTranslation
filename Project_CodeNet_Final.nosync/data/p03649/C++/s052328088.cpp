#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	long long N; cin >> N;
	long long a[55];
	long long cnt = 1;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	long long ans = 0;
	while (cnt > 0) {
		cnt = 0;
		for (int i = 0; i < N; i++) {
			if (a[i] >= N) {
				cnt = a[i] / N;
				a[i] %= N;
				for (int j = 0; j < i; j++) {
					a[j] += cnt;
				}
				for (int j = i + 1; j < N; j++) {
					a[j] += cnt;
				}
				ans += cnt;
			}
		}
	}
	cout << ans;
}