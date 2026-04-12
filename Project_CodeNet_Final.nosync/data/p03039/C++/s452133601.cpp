#include <bits/stdc++.h>

constexpr int64_t mod{1'000'000'007};

class Combination {
private:
	const int64_t mod_;

public:
	std::vector<int64_t> inv, fact, finv;

	Combination(const int max = 200'000, const int64_t mod = 1'000'000'007)
		: mod_(mod),
		inv(max + 1), fact(max + 1), finv(max + 1)
	{
		inv[0] = inv[1] = fact[0] = fact[1] = finv[0] = finv[1] = 1;
		for (int num{2}; num <= max; num++)
		{
			inv[num] = (mod_ - inv[mod_ % num] * (mod_ / num) % mod_) % mod_;
			fact[num] = num * fact[num - 1] % mod_;
			finv[num] = inv[num] * finv[num - 1] % mod_;
		}
	}

	int64_t getCombi(const int n, const int r)
	{
		if (r < 0 || n < 0 || n - r < 0) return 0;
		return fact[n] * finv[r] % mod_ * finv[n - r] % mod_;
	}

	int64_t getPerm(const int n, const int r)
	{
		if (r < 0 || n < 0 || n - r < 0) return 0;
		return fact[n] * finv[n - r] % mod_;
	}
};

int main()
{
	int64_t N, M, K;
	scanf("%lld%lld%lld", &N, &M, &K);
	if  (N > M) std::swap(N, M);

	Combination combi;
	int64_t ans{}, tmp{};
	for (int i{1}; i + 1 <= N; i++)
		tmp = (tmp + i * (N - i) % mod) % mod;
	tmp = tmp * M % mod * M % mod;
	ans = tmp;
	
	tmp = 0;
	for (int i{1}; i + 1 <= M; i++)
		tmp = (tmp + i * (M - i) % mod) % mod;
	tmp = tmp * N % mod * N % mod;
	ans = (ans + tmp) % mod;

	ans = ans * combi.getCombi((N * M - 2) % mod, (K + mod - 2) % mod) % mod;
	printf("%lld\n", ans); 

	return 0;
}