#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 200005;

string n;
int k;

ll dp[111][4][2];
ll f(int i, int non_zero, bool less) {
	if(non_zero > k) return 0;
	if(i == (int)n.size()) return non_zero == k;
	ll &ans = dp[i][non_zero][less];
	if(~ans) return ans;
	ans = 0;
	if(less) {
		for(int d = 0; d < 10; d++) {
			// coloca o digito d na posicao i do numero a construir
			ans += f(i + 1, non_zero + (d > 0), true);
		}
	}
	else {
		// o numero construido ainda eh igual ao N
		// podemos colocar um digito que vai fazer ficar menor
		// ou continuar igual

		int dig = int(n[i] - '0');
		for(int d = 0; d < dig; d++) {
			ans += f(i + 1, non_zero + (d > 0), true);
		}
		ans += f(i + 1, non_zero + (dig > 0), false);
	}
	return ans;
}

int main() {
	memset(dp, -1, sizeof dp);

	cin >> n >> k;
	cout << f(0, 0, 0) << endl;
}
