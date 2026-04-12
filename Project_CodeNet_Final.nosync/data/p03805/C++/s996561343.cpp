#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

template <class T>
inline bool chmin(T& a, T b)
{
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T& a, T b)
{
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

typedef long long ll;

#define MAX_N 10000

struct Edge {
    int to;
    int weight;
    Edge(int t, int w)
        : to(t)
        , weight(w)
    {
    }
};
using Graph = vector<vector<int>>;
using Graph_e = vector<vector<Edge>>;

vector<int> dx = { 1, 0, -1, 0 };
vector<int> dy = { 0, 1, 0, -1 };
typedef pair<int, int> P;

Graph G;
void dfs(int v, vector<bool>& seen, int& res)
{
    bool end = true;
    for (int i = 0; i < seen.size(); i++)
        if (!seen[i] && i != v) // iにまだ行ってない&&次のvがiではない
            end = false;
    if (end) {
        ++res;
        return;
    }

    seen[v] = true;
    for (auto nv : G[v]) {
        if (seen[nv])
            continue;
        dfs(nv, seen, res);
    }
    seen[v] = false;
}
int main()
{
    int N, M;
    cin >> N >> M;
    G.assign(N, vector<int>());
    rep(i, M)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> seen(N, false);
    int res = 0;
    dfs(0, seen, res);
    cout << res << endl;
}
