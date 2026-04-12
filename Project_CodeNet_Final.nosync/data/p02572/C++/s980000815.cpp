#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
	ll N; cin >> N;
	vector<ll> A(N);
	rep(i, N) cin >> A[i];

	ll ans = 0;
	vector<ll> SS(N);

	ll s = 0;
	for (int i = N - 1; i >= 1; i--)
	{
		s += A[i];

		SS[i] = s % 1'000'000'007LL;
	}

	for (int i = 0; i < N - 1; i++)
	{
		ans += A[i] * SS[i + 1];
		ans %= 1'000'000'007LL;
	}

	cout << ans << endl;

	return 0;
}