#include <stdio.h>
#include <bits/stdc++.h>

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

using namespace std;

const int N = 100000;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 31;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;
const double pi = atan2(0, -1);

vector<int> g[N];

int dfs(int u, int par)
{
    int cnt = 0;
    for (int v : g[u])
        if (v != par)
            if (dfs(v, u) == 1)
                cnt++;
    if (cnt >= 2 || cnt == 0 && par == -1)
    {
        cout << "First\n";
        exit(0);
    }
    if (cnt == 0)
        return 1;
    else
        return 0;
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    //ll TL = 0.95 * CLOCKS_PER_SEC;
    //clock_t time = clock();
    int n;
    cin >> n;
    rep(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    cout << "Second\n";
    return 0;
}
