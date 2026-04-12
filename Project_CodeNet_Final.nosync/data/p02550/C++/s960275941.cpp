#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll N, X, M;
	cin >> N >> X >> M;
	vector<int> hoge(M);
	vector<ll> sum = {0};
	ll x = X;
	int s, t;
	for (int i = 1; ; ++ i) {
		sum.push_back(sum.back() + x);
		if (hoge[x]) {
			s = hoge[x];
			t = i;
			break;
		}
		hoge[x] = i;
		x = x*x % M;
	}
	if (N < (int)sum.size()) {
		cout << sum[N] << endl;
		return 0;
	}
	ll k1 = (N - (s-1)) / (t - s);
	ll k2 = (N - (s-1)) % (t - s);
	cout << sum[s-1] + (sum[t-1]-sum[s-1]) * k1 + (sum[s-1+k2]-sum[s-1]) << endl;
}
