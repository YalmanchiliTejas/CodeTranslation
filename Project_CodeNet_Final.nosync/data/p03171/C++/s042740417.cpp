#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
typedef long long ll;

using namespace std;

int main()
{
	ll v, n;
	cin >> n;
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	vector<ll> V(n);
	for (int i = 0; i < n; i++) {
		cin >> v;
		V[i] = v;
	}
	for (int i = 0; i < n; i++) {
		dp[i][i] = V[i];
	}
	//forstekoordinat = bredde, andre = hoyde
	for (int R = 1; R < n; R++) {
		for (int L = R - 1; L >= 0; L--) {
			if (R == L) { dp[R][R] = V[R]; }
			else {
				dp[R][L] = max(V[R] - dp[R - 1][L], V[L] - dp[R][L + 1]);
			}
		}
	}
	cout << dp[n-1][0];
}