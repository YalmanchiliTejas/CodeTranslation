#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i=(a); i<(int)(b); i++)
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
using namespace std;
 
const int maxN = 1 << 24, mod = 998244353;

long long fact[maxN], tcaf[maxN];

inline void addMod(long long& a, long long b)	{   a = (a + b) % mod;  }
inline void multMod(long long& a, long long b)	{   a = a * b % mod;    }

long long qpow(long long a, long long b)
{
    long long res0 = 1;
    for (; b!=0; b>>=1)
    {
        if (b & 1)  multMod(res0, a);
        multMod(a, a);
    }
    return res0;
}

long long cf(int n, int k)
{
	bool static initd = false;
	if (!initd)
	{
		fact[0] = 1;
		FOR(i, 1, maxN)
			fact[i] = fact[i - 1] * i % mod;
		tcaf[maxN - 1] = qpow(fact[maxN - 1], mod - 2);
		for (int i=maxN-1; i>0; i--)
			tcaf[i - 1] = tcaf[i] * i % mod;
		initd = true;
	}
	if (k < 0 or k > n)
		return 0;
	long long res0 = fact[n];
	multMod(res0, tcaf[k]);
	multMod(res0, tcaf[n-k]);
	return res0;
}

void solve()
{
	int n;
	scanf ("%d", &n);
	cf(0, 0);
	long long res = 0, p2 = 1;
	FOR(i, 0, n/2)
	{
		addMod(res, cf(n, i) * p2);
		multMod(p2, 2);
	}
	
	multMod(res, 2);
	multMod(res, mod-1);
	addMod(res, qpow(3, n));
		
	printf("%lld\n", res);
}
 
int main()
{
	int t;
	t = 1;//scanf ("%d", &t);
	while (t--)
		solve();
	return 0;
}
