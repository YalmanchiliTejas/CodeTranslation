#include <cstdio>
#include <ext/pb_ds/priority_queue.hpp>
#define FOR(i, l, r) for(int i = l; i <= r; ++i)

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair <ll, int > pii;
typedef __gnu_pbds :: priority_queue <pii,  greater<pii >, pairing_heap_tag > heap;

const int N = 200010;
const int mod = 1e9 + 7;
const ll inf = 1LL << 60;

heap::point_iterator id[N];
struct edge{int to, next; ll v;} e[N << 1];
ll f[2][N], dis[2][N], len, ans;
int head[N], n, m, x, y, z, cnt, s, t;

void ins(int x, int y, int z)
{
    e[++cnt].to = y; e[cnt].next = head[x]; e[cnt].v = z; head[x] = cnt;
}

int dijkstra(int S, int fl)
{
    heap q;
    FOR(i, 1, n) dis[fl][i] = inf, id[i] = 0;
    id[S] = q.push(make_pair(0, S)); dis[fl][S] = 0; f[fl][S] = 1;
    while (!q.empty())
    {
        int x = q.top().second; q.pop();
        for(int i = head[x]; i; i = e[i].next)
        {
            int y = e[i].to;
            if (dis[fl][x] + e[i].v < dis[fl][y])
            {
                dis[fl][y] = dis[fl][x] + e[i].v;
                f[fl][y] = f[fl][x];
                if (id[y] != 0) q.modify(id[y], make_pair(dis[fl][y], y));
                else id[y] = q.push(make_pair(dis[fl][y], y));
            }
            else if (dis[fl][x] + e[i].v == dis[fl][y])
                f[fl][y] = (f[fl][y] + f[fl][x]) % mod;
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    FOR(i, 1, m)
    {
        scanf("%d%d%d", &x, &y, &z);
        ins(x, y, z); ins(y, x, z);
    }

    dijkstra(s, 0); dijkstra(t, 1);
    len = dis[0][t];

    FOR(i, 1, n) if (dis[0][i] + dis[1][i] == len && dis[0][i] == dis[1][i])
        ans = (ans + f[0][i] * f[0][i] % mod * f[1][i] % mod * f[1][i]) % mod;

    FOR(x, 1, n) for(int i = head[x]; i; i = e[i].next)
        if (dis[0][x] + e[i].v + dis[1][e[i].to] == len && dis[0][x] < dis[1][x] && dis[1][e[i].to] < dis[0][e[i].to])
            ans = (ans + f[0][x] * f[0][x] % mod * f[1][e[i].to] % mod * f[1][e[i].to]) % mod;
    printf("%lld\n", (f[0][t] * f[0][t] - ans + mod) % mod);

    return 0;
}
