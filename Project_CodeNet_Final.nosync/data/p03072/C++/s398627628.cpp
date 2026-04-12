#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int n;
int h[N], dp[N];
	
int main() {

	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> h[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		bool flag = true;
		for (int j = 1; j < i; j ++) {
			if (h[j] > h[i]) {
				flag = false;
				break;
			}
		}
		if (flag) ans ++;
	}
	cout << ans << '\n';
	return 0;
}