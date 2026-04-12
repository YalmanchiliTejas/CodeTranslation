/* f */
#include <bits/stdc++.h>
#define N 3005

using namespace std;

const int mod = 998244353;

int n, S;
int a[N], f[N];

inline int read() {
	int x = 0; bool neg = false; char ch = getchar();
	while(!isdigit(ch)) (ch == '-') && (neg = true), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return neg ? -x : x;
}

int main() {
	scanf("%d %d", &n, &S);
	for(int i = 1; i <= n; ++i)
		a[i] = read();
	
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[i] > S) continue;
		else if(a[i] == S) {
			ans = (ans + 1LL * i * (n - i + 1)) % mod;
		} else {
			ans = (ans + 1LL * f[S - a[i]] * (n - i + 1)) % mod;
			for(int j = S; j > a[i]; --j)
				(f[j] += f[j - a[i]]) %= mod;
			f[a[i]] = (f[a[i]] + i) % mod;
		}
	}
	
	printf("%d\n", ans);
	return 0;
}