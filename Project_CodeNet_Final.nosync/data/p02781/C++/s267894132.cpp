#include <bits/stdc++.h>

using namespace std;

#define il inline
#define re register
#define Rep(i, s, e) for (re int i = s; i <= e; ++i)
#define Dep(i, s, e) for (re int i = s; i >= e; --i)
#define file(a) freopen(#a".in", "r", stdin), freopen(#a".out", "w", stdout)

il int read() {
	int x = 0; bool f = true; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = false; c = getchar();}
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? x : -x;
}

char s[210];
int k, n, dp[110][5][2];

int dfs(int now, int cnt, bool eql) {
	if (now == n + 1) return cnt == k;
	if (cnt > k) return 0;
	if (dp[now][cnt][eql]) return dp[now][cnt][eql];
	int nmax = eql ? s[now] - '0' : 9, sum = 0;
	Rep(i, 0, nmax) {
		sum += dfs(now + 1, cnt + (i != 0), eql && (i == nmax));
	}
	return dp[now][cnt][eql] = sum;
}

int main() {
	gets(s + 1), k = read();
	n = strlen(s + 1);
	printf("%d", dfs(1, 0, 1));
	return 0;
}