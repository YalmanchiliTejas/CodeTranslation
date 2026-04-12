#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

long long calc1(string N) {
	return (long long)9 * (N.size() - 1) + ((long long)N[0] - '0');
}

long long calc2(string N) {
	long long ans = 0;
	rep(i, N.size() - 2)ans += 9 * ((long long)i + 1) * 9;
	ans += ((long long)N[0] - '0' - 1) * 9 * (N.size() - 1);
	rep(i, N.size() - 1) {
		if (N[i + 1] != '0') {
			ans += calc1(N.substr(i + 1));
			break;
		}
	}
	return ans;
}

int main() {
	string N; cin >> N;
	int K; cin >> K;

	long long ans = 0;
	if (K == 1)ans = calc1(N);
	if (K == 2)ans = calc2(N);
	if (K == 3) {
		rep(i, N.size() - 3)ans += 9 * 9 * ((long long)i + 2) * ((long long)i + 1) * 9 / 2;
		if (N.size() >= 3) {
			long long num = 0;
			num = ((long long)N.size() - 1) * (N.size() - 2) / 2 * 9 * 9;
			ans += ((long long)N[0] - '0' - 1) * num;
			//cout << ans << endl;
			rep(i, N.size() - 1) {
				if (N[i + 1] != '0') {
					ans += calc2(N.substr(i + 1));
					break;
				}
			}
		}
	}
	cout << ans;
}
