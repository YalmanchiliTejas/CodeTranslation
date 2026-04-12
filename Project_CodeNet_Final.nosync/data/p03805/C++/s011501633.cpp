#include <iostream>
#include <vector>
#include <numeric>

typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i <= b; i++)
#define revrep(i, s) for (int i = s-1; i > 0; i--)
#define revrrep(i, s) for (int i = s-1; i >= 0; i--)
#define all(a)  begin((a)),end((a))
#define uniq(c) (c).erase(unique(all((c))), end((c)))

using Graph = vector<vector<int>>;
int ans = 0;

bool check(vector<int> dist)
{
    for (int d : dist) {
        if (d == -1)
            return false;
    }
    return true;
}

void dfs(Graph G, vector<int> dist, int now)
{
    if (check(dist)) {
        ++ans;
        return;
    }

    for (auto next : G[now]) {
        if (dist[next] == 1) continue;
        dist[next] = 1;
        dfs(G, dist, next);
        dist[next] = -1;
    }
}

int main()
{
    int N, M; cin >> N >> M;
    Graph G(N);
    rep (i, 0, M) {
        int a, b; cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist(N, -1);
    dist[0] = 1;
    dfs(G, dist, 0);
    cout << ans << endl;
}