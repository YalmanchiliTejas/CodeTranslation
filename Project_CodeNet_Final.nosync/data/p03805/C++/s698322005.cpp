#include <bits/stdc++.h>
#define int long long
#define rng(i, l, r) for (size_t i = (l); i < (r); ++i)
#define rep(i, n) rng(i, 0, n)
#define gnr(i, l, r) for (size_t i = (r)-1; i >= (l); i--)
#define per(i, b) gnr(i, 0, b)
#define ALL(obj) (obj).begin(), (obj).end()    //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend() //...,3,2,1

using namespace std;

const int INF = 1e18;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve()
{
    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("./sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int G[10][10];
    memset(G, 0, sizeof(G));
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a][b] = 1;
        G[b][a] = 1;
    }

    vector<int> path;
    rep(i, n) path.push_back(i);

    int ans = 0;
    do
    {
        if (path[0] != 0)
            continue;
        bool isExistPath = true;
        rep(i, n - 1)
        {
            if (!G[path[i]][path[i + 1]])
                isExistPath = false;
        }

        if (isExistPath)
            ans++;

    } while (next_permutation(ALL(path)));

    cout << ans << endl;
}

signed main()
{
    solve();
    return 0;
}
