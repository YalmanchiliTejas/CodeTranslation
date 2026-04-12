#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define eFOR(i,a,n) for(int i=a;i<=n;++i)
#define rFOR(i,a,n) for(int i=n-1;a<=i;--i)
#define erFOR(i,a,n) for(int i=n;a<=i;--i)

ll dp[102][2][5];
int main() {
	string t; cin >> t;
	int n = t.length();
	vector<int> s(n);
	FOR(i, 0, n)s[i] = t[i] - '0';
	int k; cin >> k;

	dp[0][0][0] = 1;
	FOR(i, 0, n)FOR(small, 0, 2)eFOR(j, 0, k)eFOR(x, 0, (small ? 9 : min(9, s[i]))) {
		dp[i + 1][small | (x < s[i])][j + (x != 0)] += dp[i][small][j];
	}

	cout << dp[n][0][k] + dp[n][1][k] << endl;
}