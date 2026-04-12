#include<bits/stdc++.h>
using namespace std;
#define MAXN	10005
#define P	998244353
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
long long dp[2][MAXN], ans[MAXN];
long long fac[MAXN], inv[MAXN];
int both, either;
char x[MAXN], y[MAXN];
void update(long long &x, long long y) {
	x = (x + y) % P;
}
long long power(long long x, long long y) {
	if (y == 0) return 1;
	long long tmp = power(x, y / 2);
	if (y % 2 == 0) return tmp * tmp % P;
	else return tmp * tmp % P * x % P;
}
long long getc(long long x, long long y) {
	return fac[x] * inv[y] % P * inv[x - y] % P;
}
int main() {
	scanf("%s\n%s", x + 1, y + 1);
	int l = strlen(x + 1);
	for (int i = 1; i <= l; i++) {
		if (x[i] == '1' && y[i] == '1') both++;
		if (x[i] == '1' && y[i] == '0') either++;
	}
	fac[0] = 1;
	for (int i = 1; i <= l; i++)
		fac[i] = fac[i - 1] * i % P;
	inv[l] = power(fac[l], P - 2);
	for (int i = l - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % P;
	for (int i = 0; i <= either; i++)
		dp[0][i] = fac[i] * fac[i] % P;
	ans[0] = dp[0][either];
	for (int k = 1, now = 1, last = 0; k <= both; k++, now ^= 1, last ^= 1) {
		memset(dp[now], 0, sizeof(dp[now]));
		dp[now][0] = 0;
		for (int i = 1; i <= either; i++) {
			update(dp[now][i], dp[now][i - 1] * i * i);
			update(dp[now][i], dp[last][i] * i * k);
		}
		ans[k] = dp[now][either];
	}
	long long finalans = 0;
	for (int i = 0; i <= both; i++)
		update(finalans, getc(both, i) * getc(both + either, both - i) % P * fac[both - i] % P * fac[both - i] % P * ans[i] % P);
	cout << finalans << endl;
	return 0;
}