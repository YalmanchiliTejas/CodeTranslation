#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
using namespace std;

const int MAX_FACT = 200001;
unsigned long long MOD = 1e9 + 7;
unsigned long long fact[MAX_FACT], invFact[MAX_FACT], inv[MAX_FACT];

void init()
{
	fact[0] = 1;
	fact[1] = 1;
	invFact[0] = 1;
	invFact[1] = 1;
	inv[1] = 1;
	for (auto i = 2; i < MAX_FACT; ++i)
	{
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		invFact[i] = invFact[i - 1] * inv[i] % MOD;
	}
}

unsigned long long calcCombination(int n, int k)
{
	if (n < k)
	{
		return 0;
	}
	if ((n < 0) || (k < 0))
	{
		return 0;
	}

	return fact[n] * (invFact[k] * invFact[n - k] % MOD) % MOD;
}

int main()
{
	unsigned long long N, M, K;
	cin >> N >> M >> K;

	init();

	auto result = 0ull;
	for (auto i = 1; i < N; ++i)
	{
		result = (result + i * (N - i) * M % MOD * M % MOD) % MOD;
	}
	for (auto i = 1; i < M; ++i)
	{
		result = (result + i * (M - i) * N % MOD * N % MOD) % MOD;
	}

	result = (result * calcCombination(N * M - 2, K - 2)) % MOD;
	cout << result << endl;

	return 0;
}
