#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lf;

ll N, AI;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	ll cur = 0, ans = 0;
	for (ll i = 0; i < N; i++) {
		cin >> AI;
		if (AI >= cur) {
			ans++;
		}
		cur = max(cur, AI);
	}

	cout << ans << "\n";

}