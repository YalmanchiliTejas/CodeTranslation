#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

cat pow(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pow(a, e/2, mod);
	x = x * x % mod;
	if(e&1) x = x * a % mod;
	return x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	cat ans = 1, mod = 998244353;
	for(int i = 0; i < N; i++) {
		ans += 2*ans;
		if(ans >= mod) ans -= mod;
		if(ans >= mod) ans -= mod;
	}
	vector<cat> pow2(N+2, 1);
	for(int i = 1; i <= N+1; i++) {
		pow2[i] = 2 * pow2[i-1];
		if(pow2[i] >= mod) pow2[i] -= mod;
	}
	vector<cat> binom(N/2+1, 1), inv(N/2+1);
	for(int i = 1; i <= N/2; i++) {
		if(N/2-i < i) break;
		if(i > 2 && i%2 == 0) inv[i] = inv[2] * inv[i/2] % mod;
		else inv[i] = pow(i, mod-2, mod);
	}
	for(int i = 1; i <= N/2; i++) {
		if(N/2-i < i) binom[i] = binom[N/2-i];
		else binom[i] = binom[i-1] * (N/2-i+1) % mod * inv[i] % mod;
	}
	cat sum = 0;
	for(int nAL = 0; nAL <= N/2; nAL++) {
		ans = (ans - binom[nAL] * pow2[N/2-nAL+1] % mod * sum) % mod;
		sum = (sum + pow2[nAL] * binom[nAL]) % mod;
	}
	if(ans < 0) ans += mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
