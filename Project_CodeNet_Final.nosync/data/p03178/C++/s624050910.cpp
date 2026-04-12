#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;
const ll INF = 1e9+5;

int n, D;
string s;
int memo[10005][105][2];

int dp(int i, int o, bool m) {
	if (i==n) {
		if (o) return 0;
		return 1;
	}
	if (memo[i][o][m] != -1) return memo[i][o][m];
	int mxd = m?9:s[i]-'0';
	int uk = 0;
	for (int d=0 ; d<=mxd ; d++) {
		uk = (uk + dp(i+1, (o+d)%D, m|(d<s[i]-'0'))) % MOD;
	}
	return memo[i][o][m] = uk;
}

int main() {
	memset(memo, -1, sizeof memo);
	cin >>s;
	scanf("%d", &D);
	n = s.size();
	printf("%d\n", (MOD+dp(0, 0, 0)-1)%MOD);
	return 0;
}