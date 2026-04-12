#include <bits/stdc++.h>

using namespace std;

//#define FILE_IO

const int mod = 1e9 + 7;

typedef long long LL;
typedef pair<LL, int> pii;

int N, M, S, T, ans;
int cnt[2][100005];
LL d[2][100005];
vector<pii> edg[100005];
priority_queue< pii, vector<pii>, greater<pii> > pq;

void dijkstra(int id, int source)
{
    for(int i = 1; i <= N; i++) d[id][i] = 1LL << 60;
    pq.push({0LL, source});
    cnt[id][source] = 1;
    d[id][source] = 0;

    while(!pq.empty())
    {
        LL y = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if(d[id][x] != y)   continue;
        for(auto e: edg[x])
        {
            int nxt = e.first;
            LL dst = e.second;
            if(d[id][nxt] > y + dst)
            {
                d[id][nxt] = y + dst;
                cnt[id][nxt] = cnt[id][x];
                pq.push({y + dst, nxt});
            }
            else if(d[id][nxt] == y + dst)
                (cnt[id][nxt] += cnt[id][x]) %= mod;
        }
    }
}

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d%d", &N, &M);
    scanf("%d%d", &S, &T);
    for(int i = 1; i <= M; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        edg[x].push_back({y, z});
        edg[y].push_back({x, z});
    }

    dijkstra(0, S);
    dijkstra(1, T);
    LL D = d[0][T];
    LL d2 = (D / 2);
    LL d1 = ((D + 1) / 2);

    ans = (1LL * cnt[0][T] * cnt[1][S]) % mod;
    for(int i = 1; i <= N; i++)
    {
        if(d[0][i] == d[1][i])
        {
            int c = (1LL * cnt[0][i] * cnt[1][i]) % mod;
            c = (1LL * c * c) % mod;
            ans -= c;
            ans += mod;
            ans %= mod;
        }

        for(auto e: edg[i])
            if(d[0][i] + e.second == d[0][e.first] && d[0][e.first] + d[1][e.first] == d[0][T] && d[0][i] + d[1][i] == d[0][T])
            {
                int nxt = e.first;
                if(d[0][i] < d1 && d[0][nxt] > d2 && d[1][nxt] < d1 && d[1][i] > d2)
                {
                    int c = (1LL * cnt[0][i] * cnt[1][nxt]) % mod;
                    c = (1LL * c * c) % mod;
                    ans -= c;
                    ans += mod;
                    ans %= mod;
                }
            }
    }
    printf("%d\n", ans);

    return 0;
}
