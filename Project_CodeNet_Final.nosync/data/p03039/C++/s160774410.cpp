// ABC127 E - Cell Distance.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <functional>
#include <map>
#include <string>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <numeric>


using lolo=long long;
using namespace std;
using vec=vector<lolo>;
using vvec=vector<vec>;
using vecb=vector<bool>;
#define FOR(i,n) for (lolo i=0; i<n; ++i)
#define FORN(i,a,b) for (lolo i=a; i<b; ++i)
#define REV(i,a,b) for (lolo i=a; i>b; --i)
#define ALL(x) x.begin(), x.end()
constexpr lolo MOD = lolo(1e9 + 7);
lolo myPow(lolo x, lolo n, lolo m) {
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return myPow(x * x % m, n / 2, m);
	else
		return x * myPow(x, n - 1, m) % m;
}

int main()
{
	lolo N, M, K;
	cin >> N >> M >> K;
	lolo ans = 0;
	vec FAC(N*M + 2);
	FAC[0] = 1;
	FAC[1] = 1;
	FOR(i, N*M+1) {
		if (i == 0)continue;
		(FAC[i + 1] = FAC[i] * (i + 1)) %= MOD;;
	}
	vec DEFAC(N*M + 2);
	DEFAC[N * M] = myPow(FAC[N * M], MOD - 2, MOD);
	REV(i, N* M, 0) {
		DEFAC[i - 1] = (DEFAC[i] * i) % MOD;
	}

	auto getComb = [&FAC, &DEFAC](lolo n, lolo b) {
		// nCb
		
		return ((FAC[n] * DEFAC[n - b]) % MOD) * DEFAC[b] % MOD;
	};
	FOR(i, N* M) {
		auto row = i / M;
		auto col = i % M;
		lolo score = 0;
		(score += (1 + col) * col / 2 * N) %= MOD;
		(score += (1 + M - 1 - col) * (M - 1 - col) / 2 * N) %= MOD;
		(score += (1 + row) * row / 2 * M) %= MOD;
		(score += (1 + N - 1 - row) * (N - 1 - row) / 2 * M) %= MOD;
		(score *= getComb(N * M - 2, K - 2)) %= MOD;
		(score *= DEFAC[2]) %= MOD;
		(ans += score) %= MOD;
		;
	}
	cout << ans << endl;
	
}

