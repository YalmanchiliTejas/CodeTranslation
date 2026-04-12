#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];
    vector<vector<bool>> g(n, vector<bool>(n, false));
    rep(i, m)
    {
        g[a[i] - 1][b[i] - 1] = true;
        g[b[i] - 1][a[i] - 1] = true;
    }
    vector<int> p(n);
    rep(i, n) p[i] = i;
    int ans = 0;
    do
    {
        if (p[0] != 0)
            break;
        bool ok = true;
        rep(i, n - 1)
        {
            if (!g[p[i]][p[i + 1]])
                ok = false;
        }
        if (ok)
            ans++;
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}