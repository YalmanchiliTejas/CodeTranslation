#include <bits/stdc++.h>
using namespace std;
const int maxn = 3030;
int ways[maxn][maxn], sways[maxn], coef[maxn][maxn], pw[maxn * maxn], pw2[maxn * maxn], ppw2[maxn];
int main(){
	int n, m; cin >> n >> m;
	auto add = [&](int a, int b){
		a += b;
		if(a >= m) a -= m;
		if(a < 0) a += m;
		return a;
	};
	auto mul = [](long long a, long long b, int m){
		return a * b % m;
	};
	auto pwr = [&](int a, int b, int m){
		int r = 1;
		for(; b; b >>= 1, a = mul(a, a, m)) if(b&1) r = mul(r, a, m);
		return r;
	};
	for(int i = 1; i <= n; i++){
		ways[i][0] = ways[i][i] = 1;
		for(int j = 1; j < i; j++){
			ways[i][j] = add(mul(ways[i - 1][j], j + 1, m), ways[i - 1][j - 1]);
		}
	}
	pw[0] = pw2[0] = 1;
	for(int i = 1; i <= n * n; i++){
		pw[i] = mul(2, pw[i - 1], m);
		pw2[i] = mul(2, pw2[i - 1], m - 1);
	}
	for(int i = 0; i <= n; i++){
		ppw2[i] = pwr(2, pw2[i], m);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i; j++){
			ways[i][j] = mul(mul(ways[i][j], pw[(n - i) * j], m), ppw2[n - i], m);
			sways[i] = add(sways[i], ways[i][j]);
		}
	}
	for(int i = 1; i <= n; i++){
		coef[i][0] = coef[i][i] = 1;
		for(int j = 1; j < i; j++){
			coef[i][j] = add(coef[i - 1][j - 1], coef[i - 1][j]);
		}
	}
	int ans = pwr(2, pwr(2, n, m - 1), m);
	for(int i = n; i > 0; i--){
		if(i & 1) ans = add(ans, m - mul(coef[n][i], sways[i], m));
		else ans = add(ans, mul(coef[n][i], sways[i], m));
	}
	cout << ans << endl;
	return 0;
}
