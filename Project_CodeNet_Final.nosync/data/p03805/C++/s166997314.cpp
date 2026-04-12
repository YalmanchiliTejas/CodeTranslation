#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vi> g(n, vi(n));
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a][b] = g[b][a] = 1;
    }
    vi p(n);
    rep(i, n)
    {
        p[i] = i + 1;
    }
    int ans = 0;
    do
    {
        if (p[0] != 1)
            break;
        bool flag = true;
        rep(i, n - 1)
        {
            if (g[p[i] - 1][p[i + 1] - 1] == 0)
                flag = false;
        }
        if (flag)
            ans++;
    } while (next_permutation(all(p)));
    cout << ans << endl;
}