#include <bits/stdc++.h>
using namespace std;

const int64_t mod = 998244353;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int64_t N, X, M;
	cin >> N >> X >> M;

	int64_t curr = X, ans = X;
	vector<int> seen(M+5);
	seen[curr] = 1;

	for (int64_t i = 2; i <= N; ++i) {
		curr = (curr*curr)%M;
		// cout << curr << " " << seen[curr] << endl;
		ans += curr;
		if (seen[curr]) {
			int64_t rem = N-i;
			// cout << "rem " << rem << endl;
			// cout << rem << endl;
			vector<int64_t> cunt;
			int64_t at = (curr*curr)%M, s = curr;
			while (at != curr) {
				cunt.push_back(at);
				s += at;
				at = (at*at)%M;
			}
			cunt.push_back(curr);
			// for (int64_t c : cunt) {
			// 	cout << " f " << c << endl;
			// }
			if (rem < cunt.size()) {
				for (int j = 0; j < rem; ++j) {
					ans += cunt[j];
				}
			} else {
				ans += (rem/cunt.size())*s;
				// cout << (rem/cunt.size()) << "*" << s << endl;
				rem = (rem%cunt.size());
				for (int j = 0; j < rem; ++j) {
					ans += cunt[j];
				}
			}
			break;
		}
		seen[curr] = 1;
	}

	cout << ans << endl;

	
}