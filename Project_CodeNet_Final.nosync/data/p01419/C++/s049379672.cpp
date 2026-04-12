#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int R, C, M, ans;
int now=1, sr, sc, tr, tc;
int on[55][55], off[55][55], kp[55][55];
int time[55][55];
int taskr[1010], taskc[1010];
bool vis[55][55];
char g[55][55];

inline bool check(int r, int c)
{
	if (r<0 || r>=R) return 0;
	if (c<0 || c>=C) return 0;
	if (g[r][c]=='#') return 0;
	return 1;
}

void homura(int r, int c, int t)
{
	if (time[r][c]==0)
		ans += on[r][c];
	else
		ans += min(on[r][c]+off[r][c], kp[r][c]*(t-time[r][c]));
	time[r][c] = t;
}

bool dfs(int r, int c, int t)
{
	vis[r][c] = 1;
	if (r==tr && c==tc)
	{
		now = t;
		return 1;
	}
	int nr, nc;
	for (int i = 0; i < 4; ++i)
	{
		nr = r+dr[i]; nc = c+dc[i];
		if (vis[nr][nc] || !check(nr, nc)) continue;
		if (dfs(nr, nc, t+1))
		{
			homura(r, c, t);
			return 1;
		}
	}
	return 0;
}

int main()
{
	int i, j, k, r, c;
	scanf("%d%d%d", &R, &C, &M);
	for (r = 0; r < R; ++r)
		scanf("%s", g[r]);
	for (r = 0; r < R; ++r)
		for (c = 0; c < C; ++c)
			scanf("%d", &kp[r][c]);
	for (r = 0; r < R; ++r)
		for (c = 0; c < C; ++c)
			scanf("%d", &on[r][c]);
	for (r = 0; r < R; ++r)
		for (c = 0; c < C; ++c)
			scanf("%d", &off[r][c]);
	for (i = 0; i < M; ++i)
		scanf("%d%d", &taskr[i], &taskc[i]);
	for (i = 0; i < M-1; ++i)
	{
		memset(vis, 0, sizeof(vis));
		sr = taskr[i], sc = taskc[i];
		tr = taskr[i+1], tc = taskc[i+1];
		dfs(sr, sc, now);
	}
	homura(taskr[M-1], taskc[M-1], now);
	for (r = 0; r < R; ++r)
		for (c = 0; c < C; ++c)
			if (time[r][c]) ans += off[r][c];
	printf("%d\n", ans);
	return 0;
}