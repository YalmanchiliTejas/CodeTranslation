#include<stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include<stack>
#include <queue>
#include<map>
#include <set>
#include<math.h>
using namespace std;
#define int long long
#define ll long long
#define double long double
#define rep(i,n) for(ll i=0;i<n;++i)
#define loop(i,m,n) for(ll i=m;i<n;++i)
#define ggr getchar(); getchar();return 0;
#define pie 3.141592653589793238462643383279
#define elif else if
const int inf = 1000000007;
int bin(int bina) {
	int ans = 0;
	for (int i = 0; bina > 0; i++)
	{
		ans = ans + (bina % 2) * pow(10, i);
		bina = bina / 2;
	}
	return ans;
}
bool prime(int n) {
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int kai(int x) {
	if (x == 0)return 1;
	return kai(x - 1) * x % inf;
}
int mod_pow(int x, int y, int mod) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % mod;
		}
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	return kai(x)* mod_pow(kai(x - y), inf - 2, inf) % inf * mod_pow(kai(y), inf - 2, inf) % inf;
}
int a[25];
signed main() {
	int n,sum,ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sum = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] >= sum) {
			ans++;
			sum = a[i];
		}
	}
	cout << ans + 1 << endl;
}
