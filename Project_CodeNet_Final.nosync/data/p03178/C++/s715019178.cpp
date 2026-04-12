#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const long long MOD = (long long)1e9 + 7;

string s;
int d, dp1[10009][100], dp2[10009][100];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> d;
	int n = s.length();
	s = s + "0";
	reverse(s.begin(), s.end());
	dp2[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < d; j++) {
			for (int k = 0; k < 10; k++) {
				dp2[i][(k + j) % d] += dp2[i - 1][j];
				dp2[i][(k + j) % d] = dp2[i][(k + j) % d] % MOD;
			}
		}
	}
	dp1[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < s[i] - '0'; k++) {
			for (int j = 0; j < d; j++) {
				dp1[i][(k + j) % d] += dp2[i - 1][j];
				dp1[i][(k + j) % d] = dp1[i][(k + j) % d] % MOD;
			}
		}
		for (int j = 0; j < d; j++) {
			dp1[i][(s[i] - '0' + j) % d] += dp1[i - 1][j];
			dp1[i][(s[i] - '0' + j) % d] = dp1[i][(s[i] - '0' + j) % d] % MOD;
		}
	}
	cout << (dp1[n][0] - 1 + MOD)%MOD << "\n";
	//system("pause");
	return 0;
}