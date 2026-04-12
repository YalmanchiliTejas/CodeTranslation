#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double pi = acos(-1);
const double eps = 1e-9;

#define endl '\n'


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	if (s[0] != s[1] || s[1] != s[2])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	// int n, p;

	// cin >> n >> p;

	// string s;
	// cin >> s;

	// vector<vi> dp(n + 1, vi(p));

	// dp[n][0] = 1;

	// for (int i = n - 1; i >= 0; --i){
	// 	for (int j = 0; j < p; ++j){
	// 		dp[i][j] = dp[]
	// 	}
	// }


	return 0;
}