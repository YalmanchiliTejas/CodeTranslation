#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<typename T>
T gcd(T a, T b)
{
	if (a < b)	return gcd(b, a);
	T r;
	while ((r = a % b))
	{
		a = b;
		b = r;
	}
	return b;
}

template<typename T>
T lcm(T a, T b)
{
	return a * b / gcd(a, b);
}

template<typename T>
T ext_gcd(T a, T b, T& x, T& y)
{
	x = 1;
	y = 0;
	T x0 = 0, y0 = 1;
	while (b != 0)
	{
		T q = a / b;
		a -= q * b;
		swap(a, b);
		x -= q * x0;
		swap(x, x0);
		y -= q * y0;
		swap(y, y0);
	}
	return a;
}

template<typename T>
T inv_mod(T a, T mod)
{
	T t1, t2;
	ext_gcd(a, mod, t1, t2);
	t1 %= mod;
	if (t1 < 0)		t1 += mod;
	return t1;
}

template<typename T>
T combination_large(T n, T k, T mod)
{
	if (n < k || n < 0 || k < 0)	return 0;
	vector<T> inv(n + 1, 1), fact(n + 1, 1), fact_inv(n + 1, 1);
	for (T i = 2; i <= n; ++i)
	{
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		fact[i] = (fact[i - 1] * i) % mod;
		fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
	}
	return fact[n] * (fact_inv[k] * fact_inv[n - k] % mod) % mod;
}

template<typename T>
T combination(T n, T k, T mod = 1)
{
	vector<vector<T>> table(n + 1, vector<T>(k + 1, 1));
	for (T i = 1; i <= n; ++i)
	{
		table[i][0] = 1;
		for (T j = 1; j <= n; ++j)
		{
			table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
		}
	}
}


int main(int, char**)
{
	long long N;
	scanf("%lld",&N);
	long long M;
	scanf("%lld",&M);
	vector<vector<bool>> adj(N, vector<bool>(N, false));
	std::vector<long long> a(M);
	std::vector<long long> b(M);
	for(ll i = 0 ; i < M ; i++){
		ll a, b;
		scanf("%lld",&a);
		scanf("%lld",&b);
		--a;
		--b;
		adj[a][b] = true;
		adj[b][a] = true;
	}

	vector<ll> p(N);
	iota(p.begin(), p.end(), 0);
	int counter = 0;
	do {
		ll before = 0;
		bool connected = true;
		for (ll i = 1; i < N && connected; ++i)
		{
			if (!adj[before][p[i]])
			{
				connected = false;
				break;
			}
			before = p[i];
		}
		if (connected)
		{
			++counter;
		}
	} while (next_permutation(p.begin() + 1, p.end()));

	cout << counter << endl;

	return 0;
}
