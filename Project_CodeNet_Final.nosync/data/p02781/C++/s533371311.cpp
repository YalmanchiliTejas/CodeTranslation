#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;
const ll INF = 1e9+5;

string s;
ll memo[105][5][2];

int dp(int pos, int k, bool ok) {
	if (k<0) return 0;
	if (pos == s.size()) {
		if (k == 0) return 1;
		return 0;
	}
	if (memo[pos][k][ok] != -1) return memo[pos][k][ok];
	ll sol = 0;
	for (char i='0' ; i<='9' ; i++) {
		if (ok) {
			sol += dp(pos+1, k-(i>'0'), 1);
		} else {
			if (i>s[pos]) break;
			sol += dp(pos+1, k-(i>'0'), i<s[pos]);
		}
	}
	return memo[pos][k][ok] = sol;
}

int main() {
	memset(memo, -1, sizeof memo);
	int k;
	cin >>s>>k;
	cout <<dp(0, k, 0)<<endl;
	return 0;
}