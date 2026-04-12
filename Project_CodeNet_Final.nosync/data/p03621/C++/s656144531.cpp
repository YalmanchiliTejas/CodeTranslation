/*
Author: Dynamic JQ

Problem: AGC019 E - Shuffle and Swap 

Time & Date(start): Apr/13/2018 19:36

Verdict: Wrong Answer(Debugging)

Tags: Combinatics & FFT
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL MOD = 998244353;

namespace NTT
{
	LL power(LL x, LL t)
	{
		if(t == 0) return 1LL;
		LL cc = power(x, t >> 1);
		cc = cc * cc % MOD;
		if(t & 1) cc = cc * x % MOD;
		return cc;
	}
	const LL root = 3;
	const int SZ = 15;
	bool fli;
	LL uniroot(int n)
	{
		int t = (MOD - 1) / n;
		if(fli) t = MOD - 1 - t;
		return power(root, t);
	}
	void DFT(LL from[], LL to[])
	{
		int cur = 0;
		rep(i, 1 << SZ) {
			to[i] = from[cur];
			for(int j = SZ - 1; j >= 0; j --) {
				cur ^= 1 << j;
				if(cur >> j & 1) break;
			}
		}
		for(int d = 2; d <= (1 << SZ); d <<= 1) {
			LL rt = uniroot(d);
			for(int i = 0; i < (1 << SZ); i += d) {
				LL cr = 1;
				for(int j = i; j < i + (d >> 1); j ++) {
					LL fe = to[j], fo = to[j + (d >> 1)] * cr % MOD;
					to[j] = (fe + fo) % MOD;
					to[j + (d >> 1)] = (fe - fo + MOD) % MOD;
					cr = cr * rt % MOD;
				}
			}
		}
	}
	void multiply(LL u[], LL v[], LL res[])
	{
		fli = false;
		DFT(u, res);
		DFT(v, u);
		rep(i, 1 << SZ) v[i] = u[i] * res[i] % MOD;
		fli = true;
		DFT(v, res);
		rep(i, 1 << SZ) res[i] = res[i] * power(1 << SZ, MOD - 2) % MOD;
	}
}

int m, n;
LL dp[32768];
LL fac[32768];
LL ret[32768];
LL tmp0[32768], tmp1[32768], tmp2[32768];
string a, b;

void pow_poly(LL cur[], LL ans[], int t)
{
	rep(i, 32768) tmp0[i] = 0LL;
	for(int i = 0; i <= n; i ++) tmp0[i] = cur[i];
	rep(i, 32768) ans[i] = 0LL;
	ans[0] = 1LL;
	while(t > 0) {
		if(t & 1) {
			copy(ans, ans + 32768, tmp1);
			copy(tmp0, tmp0 + 32768, tmp2);
			NTT::multiply(tmp1, tmp2, ans);
			for(int i = 32767; i > n; i --) ans[i] = 0LL;
		}
		copy(tmp0, tmp0 + 32768, tmp1);
		copy(tmp0, tmp0 + 32768, tmp2);
		NTT::multiply(tmp1, tmp2, tmp0);
		for(int i = 32767; i > n; i --) tmp0[i] = 0LL;
		t >>= 1;
	}
}

LL inverse(LL x)
{
	return NTT::power(x, MOD - 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> a >> b;
	int l = a.length();
	rep(i, l) if(a[i] == '1') {
		if(b[i] == '1') n ++;
		else m ++;
	}
	fac[0] = 1;
	rep1(i, n + max(m, 1)) fac[i] = fac[i - 1] * i % MOD;
	for(int i = 0; i <= n; i ++) ret[i] = inverse(fac[i + 1]);
	pow_poly(ret, ret, m);
	LL ans = 0LL;
	for(int i = 0; i <= n; i ++)
	ans = (ans + (fac[m] * fac[n] % MOD) * (ret[i] * fac[n + m] % MOD)) % MOD;
	cout << ans << '\n';
	return 0;
}