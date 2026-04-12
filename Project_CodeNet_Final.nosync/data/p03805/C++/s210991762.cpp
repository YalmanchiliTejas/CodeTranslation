// AtCoder Beginner Contest 054
// C - One-stroke Path
// https://atcoder.jp/contests/abc054/tasks/abc054_c
// https://book.mynavi.jp/manatee/detail/id=65960
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vvi graph;
#define rep(i, n) for(int i = 0; i < (n); i++)
template<class T> istream& operator >> (istream& s, vector<T>& v)
{ for (T& x: v) { s >> x; } return s;}

int dfs(graph& g, vb& f, int v, int depth)
{
    if (f[v]) return 0;
    if (depth == g.size()) return 1;

    int res = 0;
    f[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        if (!f[g[v][i]]) res += dfs(g, f, g[v][i], depth+1);
    }
    f[v] = false;
    return res;
}

int main()
{
    int N, M; cin >>N>>M;
    graph g(N);
    rep(i, M) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vb f(N, false);
    cout << dfs(g, f, 0, 1) << endl;
}
