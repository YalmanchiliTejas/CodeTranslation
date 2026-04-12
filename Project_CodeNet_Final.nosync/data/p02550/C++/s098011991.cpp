#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using Pt = pair<int, int>;

int main()
{
	ll N, X, M;
	cin >> N >> X >> M;

	vl B(2 * M);
	B[0] = X;
	int i = 1;
	for (; i < 2 * M; ++i)
	{
		B[i] = (B[i - 1] * B[i - 1]) % M;
		if (B[i] == 0)
		{
			ll ans = 0;
			for (int j = 0; j < i; ++j)
				ans += B[j];
			cout << ans << endl;
			return 0;
		}
	}
	if (N <= M)
	{
		ll ans = 0;
		for (int j = 0; j < N; ++j)
			ans += B[j];
		cout << ans << endl;
		return 0;
	}


	int K = 0;
	for (int i = M - 2; i > -1; --i)
	{
		++K;
		if (B[M - 1] == B[i])
			break;
	}
	int stub = 0;
	for (int i = 0; i < M; ++i)
	{
		if (B[i + K] == B[i])
			break;
		++stub;
	}
	ll ans = 0;
	for (int i = 0; i < stub; ++i)
		ans += B[i];
	N -= stub;
	ll m = N / K;
	ll r = N % K;
	ll tmp = 0;
	for (int i = 0; i < K; ++i)
		tmp += B[i + stub];
	ans += tmp * m;
	for (int i = 0; i < r; ++i)
		ans += B[i + stub];
	cout << ans << endl;

	//ll ans2 = 0;
	//int x = X;
	//for (int i = 0; i < N + stub; ++i)
	//{

	//	ans2 += X;
	//	X = (X * X) % M;
	//}
	//cout << ans2 << endl;
	return 0;
}
