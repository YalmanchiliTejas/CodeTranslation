#include <bits/stdc++.h>
#define P 1000000007
using namespace std;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n, m, f[10005][2][100]; char s[10005];
int main() {
	scanf("%s", s+1), read(m);
	n = (int)strlen(s+1), f[0][1][0] = 1;
	for (int i = 0; i < n; i++) {
		int idx = s[i+1]-'0';
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < idx; k++)
				(f[i+1][0][(j+k)%m] += f[i][0][j]) %= P, 
				(f[i+1][0][(j+k)%m] += f[i][1][j]) %= P;
			(f[i+1][0][(j+idx)%m] += f[i][0][j]) %= P;
			(f[i+1][1][(j+idx)%m] += f[i][1][j]) %= P;
			for (int k = idx+1; k <= 9; k++)
				(f[i+1][0][(j+k)%m] += f[i][0][j]) %= P;
		}
	}
	return printf("%d\n", (f[n][0][0]+f[n][1][0]-1+P)%P), 0;
}
