#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int N;
	cin >> N;
	vector<ll> H(N);
	for (int i = 0;i < N;i++)
		cin >> H[i];
	int nit, xit;
	ll ans = 0, cnt;
	for (int i = 1;i < N - 1;i++) {
		nit = cnt = 0;
		xit = N - 1;
		while (nit != xit && nit < N - 1 && xit > i) {
			cnt += H[nit] + H[xit];
			ans = max(ans, cnt);
			nit += i;
			if (nit == xit) break;
			xit -= i;
		}
	}
	cout << ans << endl;
}