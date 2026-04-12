#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,mmx,abm")
#pragma GCC optimize("unroll-loops,inline")
#include <bits/stdc++.h>

using namespace std;

static const int buf_size = 4096;
 
static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;
 
inline bool isEof() {
    if (buf_pos == buf_len) {
        buf_pos = 0;
        buf_len = fread(buf, 1, buf_size, stdin);
        if (buf_pos == buf_len)
            return 1;
    }
    return 0;
}
 
inline int getChar() {
    return isEof() ? -1 : buf[buf_pos++];
}
 
inline int peekChar() {
    return isEof() ? -1 : buf[buf_pos];
}
 
inline int readChar() {
    int c = getChar();
    while (c != -1 && c <= 32)
        c = getChar();
    return c;
}
  
template<class T = int>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-') {
        s = -1;
        c = getChar();
    } else if (c == '+')
        c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

const int MOD = 998244353;
const int MAXN = 3010;
int n, s;
int a[MAXN];
int dp[MAXN];

signed main() {
	//scanf("%d%d", &n, &s);
	n = readInt();
	s = readInt();
	for (int i = 1; i <= n; i++)
		a[i] = readInt();
		//scanf("%d", &a[i]);
	int ans = 0;
	for (int i = 0; i <= s; i++)
		dp[i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int w = s - a[i]; w >= 1; w--) {
			dp[w + a[i]] += dp[w];
			dp[w + a[i]] -= MOD * (dp[w + a[i]] >= MOD);
		}
		dp[a[i]] += i;
		dp[a[i]] -= MOD * (dp[a[i]] >= MOD);
		ans += dp[s];
		ans -= MOD * (ans >= MOD);
	}
	printf("%d\n", ans);
	return 0;
}