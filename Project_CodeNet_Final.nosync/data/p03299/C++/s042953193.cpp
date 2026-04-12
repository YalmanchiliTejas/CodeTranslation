#include <algorithm>
#include <iostream>
#define mod 1000000007
#define maxn 1003
using namespace std;
int h[maxn], a[maxn], b[maxn], _h[maxn], _a[maxn], f[maxn][maxn];
int fpw(int x, int y){
	if (y < 0)
		return 1;
	int ans = 1;
	for (int i = 1; i <= y; i <<= 1, x = 1LL * x * x % mod)
		if (y & i)
			ans = 1LL * ans * x % mod;
	return ans;
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> h[i];
		a[i] = h[i];
	}
	sort(a + 1, a + 1 + n);
	int _n = 0;
	for (int i = 1; i <= n; ++ i)
		if (a[i] != a[i - 1])
			_a[++ _n] = a[i];
	for (int i = 1; i <= n; ++ i)
		_h[i] = lower_bound(_a + 1, _a + 1 + _n, h[i]) - _a;
	f[0][0] = 1;
	for (int i = 1; i <= n; ++ i){
		f[i][0] = f[i - 1][0] * 2 % mod;
		for (int j = _h[i] + 1; j <= _h[i - 1]; ++ j)
			f[i][0] = (f[i][0] + f[i - 1][j] * 2 % mod) % mod;
		int x = fpw(2, h[i] - h[i - 1]);
		for (int j = 1; j <= min(_h[i], _h[i - 1]); ++ j)
			f[i][j] = 1LL * f[i - 1][j] * x % mod;
		for (int j = _h[i - 1] + 1; j <= _h[i]; ++ j){
			if (j > 1)
				f[i][j] = 1LL * f[i - 1][0] * (fpw(2, _a[j] - _a[j - 1]) - 1) % mod * 2 % mod * fpw(2, h[i] - _a[j]) % mod;
			else
				f[1][1] = 1LL * f[0][0] * (fpw(2, _a[1]) - 2) % mod * fpw(2, h[i] - _a[1]) % mod;
		}
	}
	int ans = 0;
	for (int i = 0; i <= _h[n]; ++ i)
		ans = (ans + f[n][i]) % mod;
	cout << ans << endl;
}
