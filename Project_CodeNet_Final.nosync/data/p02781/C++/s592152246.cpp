#include <bits/stdc++.h>

using namespace std;

using LL = long long;


int K, N;
string S;

LL dp[110][4][3];


LL solve(int pos, int k, int carry) {
	if (k < 0) return 0;
	if(pos >= N) return (k==0 && carry==0);
	//if (k == 0) return 1;

	LL &p = dp[pos][k][carry];
	if(p != -1) return p;

	p = 0;

	for(int i = 0; i < 10; ++i) {
		int x = S[pos]-'0';
		if(i + carry <= x) {
			p += solve(pos + 1, k - (i != 0), 0);
		}
		else {
			p += solve(pos + 1, k - (i != 0), 1);
		}
	}

	return p;
}


int main() {

	ios_base :: sync_with_stdio(0); cin.tie(NULL);

	cin >> S >> K;

	reverse(S.begin(), S.end());

	N = S.length();
	memset(dp, -1, sizeof(dp));

	cout << solve(0, K, 0) << '\n';

	return 0;
}