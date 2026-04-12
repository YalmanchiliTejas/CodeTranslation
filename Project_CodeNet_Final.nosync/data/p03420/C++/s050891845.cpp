#include <bits/stdc++.h>
using namespace std;
#define M 100010
#define LL long long
#define rep(i, x, y) for(int i = (x); i <= (y); ++ i)
inline int read() {
	char ch = getchar(); int x = 0, f = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, m;
inline int calc(int x) {
	int o = (n + 1) / x;
	int ret = o * (x - m);
	int ex = n + 1 - o * x;
	ret += max(ex - m, 0);
	if(m == 0) ret --;
	return ret;
}
int main() {
	//freopen("in.txt", "r", stdin);
	n = read(), m = read();
	LL res = 0;
	rep(i, m + 1, n) {
		res += calc(i);
	}
	cout << res;
	return 0;
}
