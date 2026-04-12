#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
vector <pair <int, int> > G[100005];
int N, M, To[100005], From[100005];
bool Use[100005];
long long D[100005];
int Path[100005], ind;
int S, T;
bool Exist[100005];
const int MOD = 1000000007;
const long long INF = 10000000000000000;
struct Node{
int node;
long long cost;
bool operator < (const Node &b) const
{
    return cost > b.cost;
}
};
priority_queue <Node> Q;
queue <int> Q2;
void Read()
{
    cin >> N >> M >> S >> T;
    for(int i = 1; i <= M; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        G[x].push_back(make_pair(y, c));
        G[y].push_back(make_pair(x, c));
    }
}
inline bool compare(int a, int b)
{
    return D[a] < D[b];
}
void Dijkstra()
{
    Q.push({S, 0});
    for(int i = 1; i <= N; i++)
        D[i] = INF;
    D[S] = 0;
    while(!Q.empty())
    {
        Node p = Q.top();
        int n = p.node, cost = p.cost;
        Q.pop();
        if(Use[n] == 1)
            continue;
        Use[n] = 1;
        for(int i = 0; i < G[n].size(); i++)
        {
            int neighb = G[n][i].first, c = G[n][i].second;
            if(Use[neighb] == 0 && D[neighb] > D[n] + c)
            {
                D[neighb] = D[n] + c;
                Q.push({neighb, D[neighb]});
            }
        }
    }
}
inline void Add(int& x, int y)
{
    x += y;
    if(x >= MOD)
        x -= MOD;
}
void precalcPath()
{
    Q2.push(T);
    Path[++ind] = T;
    Exist[T] = 1;
    while(!Q2.empty())
    {
        int node = Q2.front();
        for(int i = 0; i < G[node].size(); i++)
        {
            int neighb = G[node][i].first, cost = G[node][i].second;
            if(Exist[neighb] == 0 && D[neighb] == D[node] - cost)
            {
                Path[++ind] = neighb;
                Exist[neighb] = 1;
                Q2.push(neighb);
            }
        }
        Q2.pop();
    }
    sort(Path + 1, Path + ind + 1, compare);
}

void precalcTo()
{
    To[T] = 1;
    for(int i = ind; i >= 1; i--)
    {
        if(To[Path[i]] != 0)
            continue;
        int node = Path[i];
        for(int j = 0; j < G[node].size(); j++)
        {
            int neighb = G[node][j].first, cost = G[node][j].second;
            if(Exist[neighb] == 0 || D[node] + cost != D[neighb])
                continue;
            Add(To[node], To[neighb]);
        }
    }
}

void precalcFrom()
{
    From[S] = 1;
    for(int i = 1; i <= ind; i++)
    {
        if(To[Path[i]] != 0)
            continue;
        int node = Path[i];
        for(int j = 0; j < G[node].size(); j++)
        {
            int neighb = G[node][j].first, cost = G[node][j].second;
            if(Exist[neighb] == 0 || D[node] - cost != D[neighb])
                continue;
            Add(From[node], From[neighb]);
        }
    }
}

void Solve()
{
    int ans = 0;
    for(int i = 1; i <= ind; i++)
    {
        int node = Path[i];
        if(D[node] == D[T] / 2 && D[T] % 2 == 0)
        {
            int number = (1LL * From[node] * To[node]) % MOD;
            int rem = (MOD - number);
            Add(rem, From[T]);
            Add(ans, (1LL * number * rem) % MOD);
        }
        if(D[node] < (D[T] + 1) / 2)
        {
            for(int j = 0; j < G[node].size(); j++)
            {
                int neighb = G[node][j].first, cost = G[node][j].second;
                if(D[neighb] == D[node] + cost && Exist[neighb] == 1 && (D[neighb] >= (D[T] + 1) / 2 && (!(D[neighb] == D[T] / 2 && D[T] % 2 == 0))))
                {
                    int number = (1LL * From[node] * To[neighb]) % MOD;
                    int rem = (MOD - number);
                    Add(rem, From[T]);
                    Add(ans, (1LL * number * rem) % MOD);
                }
            }
        }
    }
    cout << ans << "\n";
}
int main()
{
    Read();
    Dijkstra();
    precalcPath();
    precalcFrom();
    precalcTo();
    Solve();
    return 0;
}
