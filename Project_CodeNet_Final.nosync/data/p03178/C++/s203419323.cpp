#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

const int MOD = 1e9 + 7;
int DP[2][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	string K;
	int D, d;
	cin >> K >> D;
	for (int i = 0; i < K[0] - '0'; i++) DP[0][i%D]++;
	d = (K[0] - '0') % D;
	for (int i = 1; i < K.size(); i++) {
		int c = K[i] - '0';
		for (int j = 0; j < D; j++) DP[i & 1][j] = 0;
		for (int j = 0; j < c; j++) DP[i & 1][(j + d) % D] = (DP[i & 1][(j + d) % D] + 1) % MOD;
		for (int j = 0; j < D; j++) {
			for (int k = 0; k < 10; k++) {
				DP[i & 1][(j + k) % D] = (DP[i & 1][(j + k) % D] + DP[(i - 1) & 1][j]) % MOD;
			}
		}
		d = (d + K[i] - '0') % D;
	}
	cout << (DP[(K.size() - 1) & 1][0] + (d == 0) + MOD - 1) % MOD << '\n';
	return 0;
}