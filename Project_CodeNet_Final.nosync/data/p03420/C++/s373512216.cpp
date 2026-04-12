#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	ll N, K;
	cin >> N >> K;

	ll res{0};

	for (ll b = K+1; b <= N; ++b)
	{
		ll times = N / b;
		res += times * (b-K);

		ll rem = N % b;
		res += max(rem - K + 1, 0ll);
	}

	if (K == 0)
		res -= N;

	std::cout << res << std::endl;
}
