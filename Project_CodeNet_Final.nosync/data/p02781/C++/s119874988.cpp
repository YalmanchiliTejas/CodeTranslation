#include <bits/stdc++.h>
using namespace std;

//const long double PIL = 3.141592653589793238462643383279502884L;
//const double PI = 3.14159265358979323846;

#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define debug(v) {for (auto z : v) {cerr << z << ' ';} cerr << endl;}

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vll = vector<long long>;
using vii = vector<pair<int,int>>;

const int N = 105;
const int K = 4;
ll dp1[N][K], dp2[N][K];

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);
	//~ cout.tie(0);
	string s; int k;
	cin >> s >> k;
	int n = s.length();

	dp1[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (s[i-1] == '0') {
				dp1[i][j] += dp1[i-1][j];
				dp2[i][j] += dp2[i-1][j];
			}
			else {
				dp2[i][j] += dp1[i-1][j] + dp2[i-1][j];
			}

			if (j == 0) continue;

			for (char c = '1'; c <= '9'; c++) {
				if (c < s[i-1]) {
					dp2[i][j] += dp2[i-1][j-1] + dp1[i-1][j-1];
				}
				else if (c == s[i-1]) {
					dp1[i][j] += dp1[i-1][j-1];
					dp2[i][j] += dp2[i-1][j-1];
				}
				else {
					dp2[i][j] += dp2[i-1][j-1];
				}
			}
		}
	}
	cout << (dp1[n][k] + dp2[n][k]) << endl;
}
