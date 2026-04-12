#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000 + 7;
const int NMAX = 200000 + 5;

typedef long long int lint;
const lint INF = 1.5E18;

lint N, M;

vector <pair <lint, lint> > graph[NMAX];
priority_queue <pair <lint, lint> > q;
bool vis[NMAX];

void dijkstra(int node, lint dist[], lint cnt[]) {
    for (int i = 1; i <= N; ++ i)
        vis[i] = false, dist[i] = INF, cnt[i] = -1;

    q.push({0, node});
    dist[node] = 0;
    cnt[node] = 1;

    while (!q.empty()) {
        node = q.top().second;
        q.pop();
        if (vis[node])
            continue;
        vis[node] = true;

        for (auto it: graph[node]) {
            if (dist[node] + it.second < dist[it.first]) {
                dist[it.first] = dist[node] + it.second;
                cnt[it.first] = cnt[node];
                q.push(make_pair(-dist[it.first], it.first));
            }
            else if (dist[node] + it.second == dist[it.first]) {
                cnt[it.first] += cnt[node];
                if (cnt[it.first] >= MOD)
                    cnt[it.first] -= MOD;
            }
        }
    }
}

int S;
lint distS[NMAX];
lint cntS[NMAX];
int T;
lint distT[NMAX];
lint cntT[NMAX];

int main()
{
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);

    cin >> N >> M;
    cin >> S >> T;

    for (int i = 1; i <= M; ++ i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dijkstra(S, distS, cntS);
    dijkstra(T, distT, cntT);

    const lint D = distS[T];
    lint ans = (1LL * cntS[T] * cntS[T]) % MOD;

    // Meet in node
    for (int i = 1; i <= N; ++ i)
        if (distS[i] + distT[i] == D && distS[i] == distT[i]) {
            const int x = (1LL * cntS[i] * cntT[i]) % MOD;
            ans = (ans - 1LL * x * x) % MOD;
            if (ans < 0)
                ans += MOD;
        }

    // Meet on edge
    for (int i = 1; i <= N; ++ i)
        for (auto it: graph[i]) {
            const lint a = i;
            const lint b = it.first;
            const lint c = it.second;

            if (distS[a] + c + distT[b] == D) {
                const lint lBound = distS[a];
                const lint rBound = distS[b];
                if (2LL * lBound < D && D < 2LL * rBound) {
                    const int x = (1LL * cntS[a] * cntT[b]) % MOD;
                    ans = (ans - 1LL * x * x) % MOD;
                    if (ans < 0)
                        ans += MOD;
                }
            }
        }

    cout << ans << '\n';
    return 0;
}
