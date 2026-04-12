#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#define lowbit(a) ((a)&(-(a)))
using namespace std;

void file(bool opt)
{
	if (opt&&fopen("in.txt", "r"))
	{
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
}

const long long mod = 1e9 + 7;
long long  inv[200000+5];
long long  fac[200000 + 5];


long long  C(int n, int m) {
	return fac[n] * inv[m] % mod*inv[n - m] % mod;
}


void init() {
	inv[0] = fac[0] = 1;
	inv[1] = 1;
	for (int i = 1; i<=200000; i++) {
		fac[i] = fac[i - 1] * i%mod;
	}
	inv[1] = 1;
	for (int i = 2; i<=200000; i++) {
		inv[i] = (long long )(mod - mod / i)*inv[mod%i] % mod;
	}
	inv[0] = 1;
	for (int i = 1; i<=200000; i++) {
		inv[i] = inv[i - 1] * inv[i] % mod;
	}
}

long long n, m,k;
long long ans = 0;

int main()
{
	init();
	cin >> n >> m>>k;
	for (long long i = 1; i <= n - 1; i++)
		ans = (ans + i*(n - i) % mod*m%mod*m%mod) % mod;
	for (long long i = 1; i <= m - 1; i++)
		ans = (ans + i*(m - i) % mod*n%mod*n%mod) % mod;

	//cout << C(n*m - 2, k - 2) % mod << endl;
	ans = ans * C(n*m - 2, k - 2)%mod;
	cout << ans << endl;
	return 0;
}