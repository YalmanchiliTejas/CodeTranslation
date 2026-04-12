#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
#define ll long long
#define fr first
#define sc second
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int mod = 1e9 + 7;
	int N; cin >> N;
	vector<ll> v(N), psum(N + 1);

	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 0; i < N; i++) psum[i + 1] = (psum[i] + v[i]) % mod;

	ll ans = 0;
	for (int i = 0; i < N; i++)
		ans = (ans + v[i] * (psum[N] - psum[i + 1] + mod) % mod) % mod;
	cout << ans << '\n';
	return 0;
}
