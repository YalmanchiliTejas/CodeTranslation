#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 100010;
const int M = 200010;
const int mod = 1e9 + 7;
struct Edge
{
	int to,w,next;
}e[M * 2];
struct Que
{
	int id;
	ll Dis;
	Que(int id = 0, ll Dis = 0):id(id),Dis(Dis){}
};
struct cmp
{
	bool operator()(const Que &a,const Que &b){ return a.Dis > b.Dis; }
};
priority_queue< Que, vector<Que>, cmp> q;
int n, m, st, ed, cnt, head[N], v[N];
ll Dis1[N], Dis2[N], way1[N], way2[N];
struct Node
{
    int x, y, w;
}sv[2 * M];
void insert(int x,int y,int w)
{
    e[++ cnt].to = y;
    e[cnt].w = w;
    e[cnt].next = head[x];
    head[x] = cnt;
}
void dijkstra(int s,ll Dis[],ll way[])
{
	rep(i, 1, n) Dis[i] = 2147483647ll * 1000000ll, way[i] = 0;
    memset(v, 0, sizeof(v));
    Dis[s] = 0;
    way[s] = 1;
    q.push(Que(s, 0));
    while (!q.empty())
    {
        Que x = q.top();
        q.pop();
        if (v[x.id]) continue;
        v[x.id] = 1;
        for(int p = head[x.id]; p; p = e[p].next)
        {
            if (x.Dis + e[p].w < Dis[e[p].to])
            {
                Dis[e[p].to] = x.Dis + e[p].w;
                way[e[p].to] = way[x.id];
                q.push(Que(e[p].to, Dis[e[p].to]));
            }
            else
            	if (x.Dis + e[p].w == Dis[e[p].to])
                	way[e[p].to] = (way[e[p].to] + way[x.id]) % mod;
        }
    }
}
int main()
{
	n = read();
	m = read();
	st = read();
	ed = read();
    rep(i, 1, m)
    {
        int x,y,w;
        x = read();
        y = read();
        w = read();
        insert(x, y, w);
        insert(y, x, w);
        sv[i].x = x; sv[i].y = y; sv[i].w = w;
        sv[i + m].x = y; sv[i + m].y = x; sv[i + m].w = w;
    }
    dijkstra(st, Dis1, way1);
    dijkstra(ed, Dis2, way2);

    ll ans = way1[ed] * way2[st] % mod;
    rep(i, 1, n)
        if (Dis1[i] == Dis2[i] && 2 * Dis1[i] == Dis1[ed])
            {
                ll t = way1[i] * way2[i] % mod;
                t = t * t % mod;
                ans = ((ans - t) % mod + mod ) % mod;
            }
    rep(i, 1, 2 * m)
    {
        int x = sv[i].x;
        int y = sv[i].y;
        int w = sv[i].w;
        if (Dis1[x] * 2 < Dis1[ed] && Dis1[y] * 2 > Dis1[ed] && Dis1[x] + w + Dis2[y] == Dis1[ed])
        {
            ll t = way1[x] * way2[y] % mod;
            t = t * t % mod;
            ans = ((ans - t) % mod + mod) % mod;
        }
    }
    cout << ans;
    return 0;
}
