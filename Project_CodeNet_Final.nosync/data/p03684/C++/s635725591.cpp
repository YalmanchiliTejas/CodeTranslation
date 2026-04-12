#include <bits/stdc++.h>

using namespace std;

//#define FILE_IO

typedef pair<int, int> pii;
typedef pair<int, pii> p3i;
typedef long long LL;

int N;
pii p[100005];
int f[100005];
int ordx[100005], ordy[100005];
vector <p3i> edges;

int F(int x) { if(x == f[x]) return x; return f[x] = F(f[x]); }

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = {x, y};
        ordx[i] = i, ordy[i] = i;
    }

    sort(ordx + 1, ordx + N + 1,
         [](int a, int b) { if(p[a].first == p[b].first) return p[a].second < p[b].second; return p[a].first < p[b].first; });
    sort(ordy + 1, ordy + N + 1,
         [](int a, int b) { if(p[a].second == p[b].second) return p[a].first < p[b].first; return p[a].second < p[b].second; });

    for(int i = 1; i < N; i++)
    {
        edges.push_back( { p[ ordx[i + 1] ].first - p[ ordx[i] ].first, {ordx[i], ordx[i + 1]} } );
        edges.push_back( { p[ ordy[i + 1] ].second - p[ ordy[i] ].second, {ordy[i], ordy[i + 1]} } );
    }

    for(int i = 1; i <= N; i++) f[i] = i;

    sort(edges.begin(), edges.end());

    LL ans = 0;
    for(auto e: edges)
    {
        int x = e.second.first;
        int y = e.second.second;

        if(F(x) == F(y))    continue;

        ans += e.first;
        f[F(x)] = F(y);
    }

    printf("%lld\n", ans);


    return 0;
}
