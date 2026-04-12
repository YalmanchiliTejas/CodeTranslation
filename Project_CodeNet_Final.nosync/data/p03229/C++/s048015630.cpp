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
	ll N; cin >> N;
	vector<ll> A(N); REP(i, N) cin >> A[i];
	sort(A.begin(), A.end(), greater<ll>());


	ll res{0};
	ll NN = N-2;
	if (N & 1)
	{
		ll i{0};
		ll tmp{0};
		for (; i < NN/2; ++i) tmp += 2*A[i];
		tmp += A[i++];
		tmp += A[i++];
		for (; i < N; ++i) tmp -= 2*A[i];
		res = max(res, tmp);

		tmp = 0;
		i = 0;
		for (; i < NN/2+1; ++i) tmp += 2*A[i];
		tmp -= A[i++];
		tmp -= A[i++];
		for (; i < N; ++i) tmp -= 2*A[i];
		res = max(res, tmp);
	}
	else
	{
		ll i{0}, tmp{0};
		for (; i < NN/2; ++i) tmp += 2*A[i];
		tmp += A[i++];
		tmp -= A[i++];
		for (; i < N; ++i) tmp -= 2*A[i];
		res = max(res, tmp);
	}

	std::cout << res << std::endl;
}
