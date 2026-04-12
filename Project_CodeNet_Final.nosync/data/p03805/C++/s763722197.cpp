#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

int search(vvi &g, vi &flg, int cnt, int rest, int v)
{
    if (flg[v] != 0)
    {
        return cnt;
    }

    if (rest == 0)
    {
        return cnt + 1;
    }

    flg[v] = 1;

    for (int n : g[v])
    {
        cnt = search(g, flg, cnt, rest - 1, n);
    }

    flg[v] = 0;

    return cnt;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vvi g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vi flg(n);
    fill(flg.begin(), flg.end(), 0);

    cout << search(g, flg, 0, n - 1, 0) << endl;
    return 0;
}