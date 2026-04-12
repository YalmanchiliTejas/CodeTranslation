#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
long long MOD = (long long)1e9 + 7;

int n;
long long dat[3009][3009], combi[3009][3009], D0[3000009], D1[3009];

long long quickpow(long long b, int e)
{
	return e ? ((e & 1 ? b : 1)*quickpow((b*b) % MOD, e >> 1)) % MOD : 1;
}

long long gun(int a, int b)
{
	long long retval = 0;
	retval = dat[a][b];
	retval *= D0[(n - a)*b];
	retval %= MOD;
	retval *= D1[n - a];
	retval %= MOD;
	return retval;
}

long long fun(int x)
{
	long long retval = 0;
	for (int j = 0; j <= x; j++) {
		retval += gun(x, j);
		retval %= MOD;
	}
	return retval;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> MOD;
	for (int i = 0; i <= n; i++) {
		dat[i][0] = 1;
		dat[i][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			long long tmp = ((j + 1)*dat[i - 1][j]) % MOD;
			dat[i][j] = (dat[i - 1][j - 1] + tmp) % MOD;
		}
	}
	for (int i = 0; i <= n; i++) combi[i][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			combi[i][j] = combi[i - 1][j - 1];
			if (j < i) combi[i][j] += combi[i - 1][j];
			combi[i][j] %= MOD;
		}
	}
	D0[0] = 1;
	for (int i = 1; i <= 2500000; i++) {
		D0[i] = D0[i - 1] * 2;
		D0[i] %= MOD;
	}
	D1[0] = 2;
	for (int i = 1; i <= n; i++) {
		D1[i] = D1[i - 1] * D1[i - 1];
		D1[i] %= MOD;
	}
	long long ans = 0;
	for (int i = 0; i <= n; i++) {
		long long tmp = combi[n][i] * fun(i);
		tmp %= MOD;
		if (i % 2) {
			ans += MOD - tmp;
		}
		else {
			ans += tmp;
		}
		ans %= MOD;
	}
	cout << ans << E;
	//system("pause");
	return 0;
}