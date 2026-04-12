#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10, mod = 1e9 + 7;
int f[N], n, m, k, tot, ans;

int sum(int a, int b){
	int c = a + b;
	if(c >= mod)
		c -= mod;
	if(c < 0)
		c += mod;
	return c;
}
int mul(int a, int b){
	return 1LL * a * b % mod;
}
int pow(int n, int k){
	int res = 1;
	for (; k; k /= 2){
		if(k % 2 == 1)
			res = mul(res, n);
		n = mul(n, n);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m >> k;
  	int a1 = 1LL * n * (n - 1) / 2 % mod, a2 = 1LL * m * (m - 1) / 2 % mod;
  	tot = sum(mul(a1, m), mul(a2, n));
	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mul(f[i - 1], i);
	int r = mul(f[n * m - 2], mul(pow(f[k - 2], mod - 2), pow(f[n * m - k], mod - 2)));

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if(j != 1 || i != 1)
				if(j == 1)
					tot = sum(tot, mod - mul(m, n - i + 1));
				else
					tot = sum(tot, sum(mul(n - i, j - 1), mod - mul(n - i + 1, m - j + 1)));
			
			ans = sum(ans, mul(r, tot));
		}
	}
	cout << ans;
}

