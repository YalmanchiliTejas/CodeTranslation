/* 
	بسم الله الرحمن الرحیم
	
	(; طلا یک جهانی
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100 * 1000 + 5;
int n, s[MAX_N];
bool mark[MAX_N];

void read_input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
}

void solve() {
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		long long sum = 0;
		for (int j = 0; j < (n - 1) / i && !mark[i * j] && !mark[n - 1 - i * j] && i * j != n - 1 - i * j; j++) {
			sum += s[i * j] + s[n - 1 - i * j];
			mark[i * j] = mark[n - 1 - i * j] = true;
			ans = max(ans, sum);
		}
		for (int j = 0; j < (n - 1) / i; j++)
			mark[i * j] = mark[n - 1 - i * j] = false;
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	read_input();
	solve();
}
