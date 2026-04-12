#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rev(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rev2(i, s, n) for (int i = (int)(n) - 1; i >= (int)(s); i--)
#define bitrep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define all(v) v.begin(), v.end()
#define println(x) cout << x << endl
#define fi first
#define se second
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")
using pii = pair<int, int>;

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int>());
    vector<int> idx(n);
    iota(all(idx), 0);
    rep(i, m)
    {
        int from, to; cin >> from >> to;
        g[from - 1].push_back(to - 1);
        g[to - 1].push_back(from - 1);
    }
    int cnt = 0;
    do
    {
        if (idx[0] != 0) break;
        vector<bool> visited(n, false);
        bool reachable = true;
        rep(i, n-1)
        {
            if (visited[idx[i]])
            {
                reachable = false;
                break;
            }
            visited[idx[i]] = true;
            if (find(all(g[idx[i]]), idx[i+1]) == g[idx[i]].end())
            {
                reachable = false;
                break;
            }
        }
        if (reachable) cnt++;
    } while (next_permutation(all(idx)));
    cout << cnt++ << endl;
}