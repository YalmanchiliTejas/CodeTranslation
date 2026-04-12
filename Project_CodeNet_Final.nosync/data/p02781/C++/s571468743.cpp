#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<stack>
#include<set>
#include<map>
#include<stdio.h>

using ll = long long;

using namespace std;

ll mod = 1000000007;

ll n_pow(ll a, ll n) {
	if (n == 0)return 1;
	ll t = n_pow(a, n / 2);
	t *= t;
	t %= mod;
	if (n % 2 == 1)t *= a;
	return t % mod;
}

const int INF = 1001001001;


int main() {
	string s;
	cin >> s;
	ll n = s.size();
	int k;
	cin >> k;
	vector<vector<int>>dp0(n + 1, vector<int>(k + 1));
	vector<vector<int>>dp1(n + 1, vector<int>(k + 1));
	dp0[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k + 1; j++) {
			int x = s[i] - '0';
			for (int d = 0; d < 10; d++) {
				int ni = i + 1, nj = j;
				if (d != 0)nj++;
				if (nj > k)continue;
				if (d == x) {
					dp0[ni][nj] += dp0[i][j];
					//dp1[ni][nj] += dp0[i][j];
				}
				if (d < x) {
					dp1[ni][nj] += dp0[i][j];
				}
				dp1[ni][nj] += dp1[i][j];

			}
		}
	}
	cout << dp0[n][k] + dp1[n][k] << endl;
	return 0;
}