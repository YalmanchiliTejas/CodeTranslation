#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

#ifdef WIN32
	#define LL "%I64d"
#else
	#define LL "%lld"
#endif

#ifdef CT
	#define debug(...) printf(__VA_ARGS__)
	#define setfile() 
#else
	#define debug(...)
	#define filename ""
	#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout)
#endif

#define R register
#define getc() (S == T && (T = (S = B) + fread(B, 1, 1 << 15, stdin), S == T) ? EOF : *S++)
#define dmax(_a, _b) ((_a) > (_b) ? (_a) : (_b))
#define dmin(_a, _b) ((_a) < (_b) ? (_a) : (_b))
#define cmax(_a, _b) (_a < (_b) ? _a = (_b) : 0)
#define cmin(_a, _b) (_a > (_b) ? _a = (_b) : 0)
#define cabs(_x) ((_x) < 0 ? (- (_x)) : (_x))
char B[1 << 15], *S = B, *T = B;
inline int F()
{
	R char ch; R int cnt = 0; R bool minus = 0;
	while (ch = getc(), (ch < '0' || ch > '9') && ch != '-') ;
	ch == '-' ? minus = 1 : cnt = ch - '0';
	while (ch = getc(), ch >= '0' && ch <= '9') cnt = cnt * 10 + ch - '0';
	return minus ? -cnt : cnt;
}
#define maxn 110
struct Edge
{
	Edge *next;
	int to;
}*last[maxn], e[1100000], *ecnt = e;
inline void link(R int a, R int b)
{
	*++ecnt = (Edge) {last[a], b}; last[a] = ecnt;
	*++ecnt = (Edge) {last[b], a}; last[b] = ecnt;
}
int f[1024][10];
bool inq[1024][10];
struct Queue
{
	int now, st;
};
std::queue<Queue> q;
int main()
{
//	setfile();
	R int n = F(), m = F();
	for (R int i = 1; i <= m; ++i) link(F(), F());
	f[1][1] = 1; q.push((Queue) {1, 1});
	int ans = 0;
	while (!q.empty())
	{
		R Queue now = q.front(); q.pop(); inq[now.st][now.now] = 0;
		if (now.st == (1 << n) - 1) {++ans; continue;}
		for (R Edge *iter = last[now.now]; iter; iter = iter -> next)
			if ((now.st & (1 << (iter -> to - 1))) == 0)
			{
				int ns = now.st | (1 << (iter -> to - 1));
				q.push((Queue) {iter -> to, ns});
			}
	}
	printf("%d\n", ans );
	return 0;
}
