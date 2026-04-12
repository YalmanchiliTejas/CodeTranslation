#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)

int const N = 200000, md = 1e9 + 7;
char s[N + 1];
int dp[N + 1], n, m;

inline void ad(int &x, int y) { if ((x += y) >= md)x -= md; }
inline void sb(int &x, int y) { if ((x -= y) <  0 )x += md; }
inline void out(int an) { printf("%d\n", an); exit(0); }

void sad(){
	dp[0] = 1;
	dp[1] = 1;
	f(i, 2, n + 1)ad(dp[i] = dp[i - 1], dp[i - 2]);
	int an = dp[n];
	ad(an, dp[n - 2]);
	out(an);
}

int main(){
	scanf("%d%d%s", &n, &m, s);
	int mx = md;
	bool im = false;
	f(i, 0, m){
		int j = i;
		while (j + 1 < m && s[j + 1] == s[i])++j;
		if (i == 0 && j + 1 == m)sad();
		im = !im;
		if (im && j + 1 != m){
			int ln = j - i + 1;
			if (ln & 1)mx = min(mx, ln);
			else if (i == 0)mx = min(mx, ln | 1);
		}
		i = j;
	}
	if (n & 1)out(0);
	n >>= 1;
	mx = mx + 1 >> 1;
	int l = 1, s = 0;
	f(i, 1, n + 1){
		if (i - l > mx)sb(s, dp[l++]);
		dp[i] = s;
		if (i <= mx)ad(dp[i], i << 1);
		ad(s, dp[i]);
	}
	out(dp[n]);
}