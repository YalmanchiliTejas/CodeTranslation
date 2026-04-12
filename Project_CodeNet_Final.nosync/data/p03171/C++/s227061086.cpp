#include <bits/stdc++.h>
#define REP(i, a, b) for(int i(a); i <= (b); ++i)

#define gc getchar()
struct Reader {
	template <class T> inline operator T() {
		T w; char c, p = 0;
		for(; !isdigit(c = gc); c == '-' && (p = 1));
		for(w = c & 15; isdigit(c = gc); w = w * 10 + (c & 15));
		return p ? -w : w;
	}
}rd;

template <class T> inline bool smin(T&x, const T&y) { return y < x ? x = y, 1 : 0; }
template <class T> inline bool smax(T&x, const T&y) { return x < y ? x = y, 1 : 0; }

typedef long long ll;

const int N(3005);
int n, a[N];
bool vis[N][N];
ll f[N][N];
ll dfs(int t, int x){
	if (t > n) return 0;
	if(vis[t][x])return f[t][x];
	vis[t][x] = 1;
	return f[t][x] = t & 1 ? std::max(a[x] + dfs(t + 1, x + 1), a[n - t + x] + dfs(t + 1, x)) : std::min(-a[x] + dfs(t + 1, x + 1), -a[n - t + x] + dfs(t + 1, x));
}
int main() {
	n = rd;
	REP(i, 1, n) a[i] = rd;
	std::cout << dfs(1, 1);
	return 0;
}

