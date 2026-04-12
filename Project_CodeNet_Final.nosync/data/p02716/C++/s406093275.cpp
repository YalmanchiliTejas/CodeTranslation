#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<n;i++)
#define P pair<int,int>
#define F first
#define S second
#define int long long
#define mod 1000000007
#define mmod 998244353
#define all(v) v.begin(), v.end()
#define INF LLONG_MAX/3
using namespace std;
int mypow(int fa, int fb, int fc) {
	if (fb == 0)return 1;
	if (fb % 2)return mypow(fa, fb - 1, fc)*fa%fc;
	int z = mypow(fa, fb / 2, fc);
	return z * z%fc;
}
int k(int fa) {
	int x = 0;
	while (fa) {
		x++;
		fa /= 10;
	}
	return x;
}
int gcd(int fa, int fb) {
	if (fb == 0)return fa;
	return gcd(fb, fa%fb);
}
int a[200000],x[200000],y[200000],z[200000];
signed main() {
	int n, vx = 0, vy = 0;
	cin >> n;
	f(i, n) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i % 2) {
			y[vy] += a[i];
			if (vy)y[vy] += y[vy - 1];
			vy++;
		}
		else {
			x[vx] += a[i];
			if (vx)x[vx] += x[vx - 1];
			vx++;
		}
	}
	f(i, n / 2) {
		if (i) {
			if (n % 2)z[i] = max(z[i - 1], x[i] - y[i]);
			else z[i] = max(z[i - 1], y[i] - x[i]);
		}
		else {
			if (n % 2)z[i] = max(z[i], x[i] - y[i]);
			else z[i] = max(z[i], y[i] - x[i]);
		}
	}
	int ans = 0;
	if (n % 2) {
		int ma = 0;
		f(i, n / 2) {
			ans += a[i * 2];
		}
		f(i, n / 2) {
			ma= max(ma,y[n / 2 - 1 - i] - x[n / 2 - i] + x[0]+ z[n / 2 - 1 - i]);
		}
		ans += ma;
	}
	else {
		f(i, n / 2) {
			ans += a[i * 2];
		}
		ans += z[n / 2 - 1];
	}
	cout << ans << endl;
}
