#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N, M, L, K, X, Y, Z;
ll ans = 0;
int main() {
	cin >> N >> X;
	vector<ll> humb(N + 1);
	vector<ll> p(N + 1);
	humb[0] = 1;
	p[0] = 1;
	for (ll i = 1; i <= N; i++)
	{
		humb[i] = humb[i - 1] * 2 + 3;
		p[i] = p[i - 1] * 2 + 1;
	}
	for (ll i = N-1; i >= 0; i--) {
		if (X == 0)break;
		X--;
		if (X / (humb[i]+1) ==1) {
			ans += (p[i] + 1);
			X -= (humb[i] + 1);
		}
		else if (X / (humb[i] + 1) == 2) {
			ans += 2 * p[i] + 1;
		}
	}
	if (X == 1)ans++;
	cout << ans << endl;
}
