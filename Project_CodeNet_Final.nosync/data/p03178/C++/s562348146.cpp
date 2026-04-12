/* be name Khoda */
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7, N = 107, M = 10 * 1000 + 7;
int size, d;
string s;

int dp[M][2][N];

int place(int at, bool restrict, int md) {
	md %= d;
	if (at == size + 1)
		return md == 0;
	if (dp[at][restrict][md] != -1)
		 return dp[at][restrict][md];
	int ans = 0;
	for (int here = 0; here < 10; here++) {
		if (!restrict) 
			ans += place(at + 1, false, (md + here) % d);
		else {
			if (here < (s[at - 1] - '0'))
				ans += place(at + 1, false, (md + here) % d);
			else if (here == (s[at - 1] - '0'))
				ans += place(at + 1, true, (md + here) % d);
			else 
				continue;
		}
		ans %= MOD;
	}
	return dp[at][restrict][md] = ans % MOD;
}

int main() {
	for (int i=0; i < 10001; i++) 
		for (int j = 0; j < 2; j++) 
			for (int k = 0; k < 101; k++) 
				dp[i][j][k] = -1;
	cin >> s >> d;
	size = s.size();
	cout << (place(1, true, 0) - 1 + MOD) % MOD << endl;
}

