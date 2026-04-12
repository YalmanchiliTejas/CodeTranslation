#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include <chrono>
//#include <random>

#define fio ios_base::sync_with_stdio(false)
#define pdl cout << "*" << endl
#define MOD 1000000007
#define INF 1000000000
#define INFLL 1000000000000000000ll
#define long int64_t
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1){ std::cerr << name << " : " << arg1 << std::endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{ const char* comma = strchr(names + 1, ','); std::cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma+1, args...); }

using namespace std;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<> dis(0, INF<<1);

const int N = 10000001;
const int mod = 998244353;

int modexp(int a, int b = mod - 2)
{
	int r = 1;
	while(b)
	{
		if(b & 1)
			r = (r * 1ll * a) % mod;
		a = (a * 1ll * a) % mod;
		b >>= 1;
	}
	return r;
}

int f[N];

int main()
{
	fio;
	f[0] = 1;
	for(int i=1; i<N; i++)
		f[i] = (f[i-1] * 1ll * i) % mod;
	int n, t = 1, a = 0;
	cin >> n;
	for(int i=(n >> 1) + 1; i<=n; i++)
	{
		t = (3ll * t) % mod;
		int x = (modexp(f[i]) * 1ll * modexp(f[n-i])) % mod;
		x = (x * 1ll * f[n]) % mod;
		x = (x * 1ll * modexp(2, n-i)) % mod;
		a += x;
		a %= mod;
	}
	a = (a + a) % mod;
	t = (t * 1ll * t) % mod;
	cout << (t - a + mod) % mod << endl;
	return 0;
}