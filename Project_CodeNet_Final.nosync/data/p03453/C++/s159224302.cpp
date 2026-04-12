#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E18;
const int MAXN = 1E5;
const int MOD = 1E9 + 7;
vector<pair<int, int>> adjList[MAXN + 1];
int ways1[MAXN + 1];
int ways2[MAXN + 1];
long long dist1[MAXN + 1];
long long dist2[MAXN + 1];
int path1[MAXN + 1];
int path2[MAXN + 1];
bool visited1[MAXN + 1];

inline int add(int a, int b)
{
    if (a + b >= MOD)
        return a + b - MOD;
    return a + b;
}

void dijkstra(int s, int ways[MAXN + 1], long long dist[MAXN + 1], bool visited[MAXN + 1], int path[MAXN + 1])
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    fill(dist, dist + MAXN + 1, INF);
    dist[s] = 0;
    ways[s] = 1;
    pq.push(make_pair(0LL, s));
    path[s] = -1;
    while (!pq.empty())
    {
        pair<long long, int> pr = pq.top();
        pq.pop();
        int v = pr.second;
        if (visited[v])
            continue;
        long long d = pr.first;
        visited[v] = true;
        for (pair<int, int> edge : adjList[v])
        {
            int adj = edge.first;
            int w = edge.second;
            if (!visited[adj])
            {
                if (d + w < dist[adj])
                {
                    path[adj] = v;
                    dist[adj] = d + w;
                    pq.push(make_pair(dist[adj], adj));
                }
            }
            else if (v != s)
            {
                if (dist[adj] + w == dist[v])
                {
                    ways[v] = add(ways[v], ways[adj]);
                }
            }
        }
    }
}

void process(int v, int u, int &exclude)
{
    int temp = (int) (((long long) ways1[v] * ways2[u]) % MOD);
    temp = (int) (((long long) temp * ways1[v]) % MOD);
    temp = (int) (((long long) temp * ways2[u]) % MOD);
    exclude = add(exclude, temp);
}

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        adjList[u].push_back(make_pair(v, d));
        adjList[v].push_back(make_pair(u, d));
    }
    dijkstra(s, ways1, dist1, visited1, path1);
    fill(visited1, visited1 + MAXN + 1, false);
    dijkstra(t, ways2, dist2, visited1, path2);
    long long shortest = dist1[t];
    int exclude = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist1[i] + dist2[i] > shortest)
            continue;
        if (2 * dist1[i] == shortest)
        {
            process(i, i, exclude);
        }
        else
        {
            for (pair<int, int> edge : adjList[i])
            {
                int adj = edge.first;
                int w = edge.second;
                if (dist1[adj] + w + dist2[i] == shortest && 2 * dist1[i] > shortest && 2 * dist1[adj] < shortest)
                {
                    process(adj, i, exclude);
                }
            }
        }
    }
    int ans = (int) (((long long) ways1[t] * ways1[t]) % MOD);
    //(int) (((long long) cnt1 * cnt2) % MOD);
    ans = add(ans, MOD - exclude);
    cout << ans << endl;
    return 0;
}
