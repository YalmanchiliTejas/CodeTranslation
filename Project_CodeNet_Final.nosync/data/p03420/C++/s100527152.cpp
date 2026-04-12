#ifdef LOCAL
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#else
#include <bits/stdc++.h>
#endif
using namespace std ;

typedef long long ll ;
#define rep(i , n ) for ( int i =0; i < n ; i++)
#define _sort(arg) sort(begin(arg), end(arg))
#define MOD 1000000007
#define pb push_back
#define DEBUG(x) cout << #x << ": " << x << endl;

class UnionFind {
private:
	unsigned size_; 
	std::vector<unsigned> par, rank;
public:
	UnionFind() : size_(0), par(std::vector<unsigned>()), rank(std::vector<unsigned>()) {};
	UnionFind(unsigned size__) : size_(size__) {
		par.resize(size_); rank.resize(size_);
		for (unsigned i = 0; i < size_; i++) par[i] = i, rank[i] = 0;
	}
	unsigned size() { return size_; }
	//unsigned root(unsigned x) { return par[x] == x ? x : par[x] = root(par[x]); }
	unsigned root(unsigned x)
	{
		while(par[x] != x)
		{
			par[x] = par[par[x]];
			x = par[x];
		}
		return x;
	}
	bool same(unsigned x, unsigned y) { return root(x) == root(y); }
	void unite(unsigned x, unsigned y) {
		x = root(x), y = root(y);
		if (x == y) return;
		if (rank[x] < rank[y]) par[x] = y;
		else if (rank[x] == rank[y]) par[y] = x, rank[x]++;
		else par[y] = x;
	}
	bool operator==(const UnionFind &u) { return par == u.par; }
	bool operator!=(const UnionFind &u) { return par != u.par; }
};

/*
maybe sth wrong 
got wa in one problem
*/
ll modpow(ll a, ll b)
{
	if (b == 0)
	{
		return 1;
	}

	if (b % 2)
	{
		return a * modpow(a, b-1) % MOD;
	}
	else
	{
		ll halfB = b / 2;
		ll half = modpow(a, halfB);
		return half * half % MOD;
	}
}

ll calcComb(ll n, ll m)
{
	if (m > n-m)
	{
		return calcComb(n, n-m);
	}

	ll ansMul = 1;
	ll ansDiv = 1;

	rep(i, m)
	{
		ansMul *= (n-i);
		ansDiv *= (i+1);
		ansMul %= MOD;
		ansDiv %= MOD;
	}

	return ansMul * modpow(ansDiv, MOD - 2) % MOD;
}

__attribute__((constructor))
void initial()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
}


int main()
{
	int n, k;
	
	cin >> n >> k;

	if (k == 0)
	{
		cout << (ll)n * (ll)n << endl;
		return 0;
	}

	ll ans = 0;

	for(ll i = 1; i < n+1; i++)
	{
		
		if (i-1 >= k)
		{
			ans += (n / i) * (i - k);
			ans += max((n % i)- k + 1, 0ll);
		}
		
	}

	cout << ans << endl;

	return 0;
}
