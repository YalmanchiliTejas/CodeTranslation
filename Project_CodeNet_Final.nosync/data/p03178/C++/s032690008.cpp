#include <bits/stdc++.h>
using namespace std;
#define int long long

string K;
const int M = 1e9 + 7;
int D, mem[10005][105][2];

int dp(int n, int r, bool b) {
	if (n == K.size()) return r == 0;
	if (mem[n][r][b] != -1) return mem[n][r][b];
	int v = 0;
	if (b) {
		for (int i = 0; i <= K[n] - '0'; i++)
			v += dp(n + 1, (r + i) % D, i == K[n] - '0'), v %= M;
	} else {
		for (int i = 0; i <= 9; i++)
			v += dp(n + 1, (r + i) % D, 0), v %= M;
	}
	return mem[n][r][b] = v;
}

int f() {
	int v = 0;
	for (int i = 0; i < K.size(); i++)
		for (int j = 1; j <= (i ? 9 : K[0] - '0'); j++)
			v += dp(i + 1, j % D, (i ? 0 : j == K[0] - '0')), v %= M;
	return v;
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> K >> D;
	cout << f() << '\n';
}
