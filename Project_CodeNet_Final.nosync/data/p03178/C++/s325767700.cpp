#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
const int D = 105;
const int mod = 1e9 + 7;

void add(int &x,int y) {
	x += y; if (x >= mod) x -= mod;
}

int n, d;
char s[N];
int f[N][D][2][2];

#define go(i, l, r) for (int i = l; i <= r; ++i)

int main() {
	scanf("%s %d", s + 1, &d);
	int n = strlen(s + 1);
	f[0][0][0][1] = 1;
	go(i, 1, n) go(sm, 0, d) go(sml, 0, 1) go(z, 0, 1) {
		int ft = f[i - 1][sm][sml][z];
		if (ft == 0) {
			continue;
		}
		int mx = 9;
		if (!sml) mx = s[i] - '0';
		go(nxt, 0, mx) {
			int nsm = (sm + nxt) % d;
			int nsml = (sml || (nxt < (s[i] - '0')));
			int nz = (z && (nxt == 0));
			add(f[i][nsm][nsml][nz], ft);
		}
	} 
	printf("%d\n", (f[n][0][0][0] + f[n][0][1][0]) % mod);
}