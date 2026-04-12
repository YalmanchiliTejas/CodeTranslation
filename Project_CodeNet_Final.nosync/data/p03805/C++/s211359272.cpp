#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int e[10][10] = {};
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e[a][b] = e[b][a] = 1;
    }
    vector<int> perm(n);
    rep(i, n) perm[i] = i;
    int ans = 0;
    do
    {
        if (perm[0] != 0)
            break;
        bool f = true;
        rep(i, n - 1) if (!e[perm[i]][perm[i + 1]]) f = false;
        if (f)
            ans++;
    } while (next_permutation(all(perm)));
    cout << ans << endl;
}