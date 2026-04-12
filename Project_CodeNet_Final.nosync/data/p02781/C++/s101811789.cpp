#pragma once

#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, char, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

const ll mod = 1000000007;

int main(void)
{
	string s;
	cin >> s;
	int k;
	cin >> k;
	int n = s.size();
	vector<ll> digits(n, 0);
	rep(i, n) {
		char c = s[i];
		digits[n-1-i] = c - '0';
	}
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(110, vector<ll>(2, 0)));
	dp[n - 1][1][1] = 1;
	dp[n - 1][1][0] = digits[n - 1]-1;
	dp[n - 1][0][0] = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (digits[i] == 0) {
			rep(j, 109) {
				//0
				dp[i][j][1] += dp[i + 1][j][1];
				dp[i][j][0] += dp[i + 1][j][0];
				//1..9
				dp[i][j+1][0] += 9 * dp[i + 1][j][0];
			}
		}
		else {
			rep(j, 109) {
				//0
				dp[i][j][0] += dp[i + 1][j][1];
				dp[i][j][0] += dp[i + 1][j][0];
				//1..d-1				
				dp[i][j+1][0] += (digits[i]-1) * dp[i+1][j][1];
				dp[i][j+1][1] +=  dp[i+1][j][1];
				//1..9
				dp[i][j+1][0] += 9 * dp[i + 1][j][0];
			}
		}
	}
	cout << dp[0][k][0] + dp[0][k][1] << endl;
	return 0;
}
