#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 3001;
inline char get() {
	static char buf[10000], *S = buf, *T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, 10000, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}
inline void read(int &x) {
	static char c; x = 0; int sgn = 0;
	for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
	for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
	if (sgn) x = -x;
}

int n;
int a[N];
ll dp[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  read(n);
  for (int i = 0; i < n; i++) {
    read(a[i]);
  }
  for (int sz = 0; sz < n; sz++) {
    for (int l = 0; l+sz < n; l++) {
      int r = l + sz;
      dp[l][r] = max(-dp[l+1][r] + a[l], -dp[l][r-1] + a[r]);
    }
  }
  cout << dp[0][n-1] << nl;
  return 0;
}
