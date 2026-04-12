/*
    Take me to church
    I'll worship like a dog at the shrine of your lies
    I'll tell you my sins and you can sharpen your knife
    Offer me that deathless death
    Good God, let me give you my life
*/
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100005, Mod = 1e9 + 7;
int n, m, s, t, dp[N][2];
long long D[N][2];
vector < pair < int , int > > Adj[N];
priority_queue < pair < long long , int > > Pq;
inline void SSSP(int st, int w)
{
    D[st][w] = 0;
    dp[st][w] = 1;
    Pq.push({0, st});
    while (Pq.size())
    {
        int v = Pq.top().y;
        long long d = - Pq.top().x;
        Pq.pop();
        if (d > D[v][w])
            continue;
        for (auto u : Adj[v])
        {
            if (D[u.x][w] > D[v][w] + u.y)
            {
                dp[u.x][w] = 0;
                D[u.x][w] = D[v][w] + u.y;
                Pq.push({- D[u.x][w], u.x});
            }
            if (D[u.x][w] == D[v][w] + u.y)
            {
                dp[u.x][w] += dp[v][w];
                if (dp[u.x][w] >= Mod)
                    dp[u.x][w] -= Mod;
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i ++)
    {
        int v, u, d;
        scanf("%d%d%d", &v, &u, &d);
        Adj[v].push_back({u, d});
        Adj[u].push_back({v, d});
    }
    memset(D, 63, sizeof(D));
    SSSP(s, 0); SSSP(t, 1);
    int tot = 1LL * dp[t][0] * dp[t][0] % Mod;
    for (int i = 1; i <= n; i ++)
        if (D[i][0] * 2 == D[t][0] && D[i][1] * 2 == D[t][0])
            tot = (tot - 1LL * dp[i][0] * dp[i][1] % Mod * dp[i][0] % Mod * dp[i][1] % Mod + Mod) % Mod;
    for (int i = 1; i <= n; i ++)
        for (auto u : Adj[i])
            if (D[i][0] + u.y + D[u.x][1] == D[t][0] && D[i][0] * 2 < D[t][0] && D[u.x][1] * 2 < D[t][0])
                tot = (tot - 1LL * dp[i][0] * dp[u.x][1] % Mod * dp[i][0] % Mod * dp[u.x][1] % Mod + Mod) % Mod;
    return !printf("%d\n", tot);
}