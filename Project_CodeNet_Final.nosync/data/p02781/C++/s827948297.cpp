#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	string n; cin >> n;
	int k, l; cin >> k;
	l = n.size();
	vector<vector<ll>> dp0(l+1, vector<ll>(k+1, 0));
	vector<vector<ll>> dp1(l+1, vector<ll>(k+1, 0));
	dp0[1][0] = 1;
	dp0[1][1] = (n[0] - '0') - 1;
	dp1[1][1] = 1;
	for (int i=2; i<l+1; i++) {
		int c = n[i-1] - '0';
		for (int j=0; j<k+1; j++) {
			dp0[i][j] += dp0[i - 1][j];
			if (j>0) dp0[i][j] += 9 * dp0[i - 1][j - 1];
			if (c==0) {
				dp1[i][j] = dp1[i - 1][j];
			} else {
				if (j>0) {
					dp1[i][j] += dp1[i - 1][j - 1];
					dp0[i][j] += (c - 1) * dp1[i - 1][j - 1];
				}
				dp0[i][j] += dp1[i- 1][j];
			}
		}
	}
	cout << dp0[l][k] + dp1[l][k] << endl;
	return 0;
}