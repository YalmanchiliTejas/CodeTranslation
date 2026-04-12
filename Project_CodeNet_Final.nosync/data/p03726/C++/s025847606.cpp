//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()

typedef pair<bool, bool> anst;
anst dfs (int x, int p, const vvi &g)
{
    vector<anst> sons;
    for (int dest : g[x]) if (dest != p)
        sons.pb(dfs(dest, x, g));

    anst res(false, true);
    for (auto pr : sons)
        res.snd &= pr.fst;
    int cnt = 0, who = -1;
    forn (i, sz(sons))
    {
        if (!sons[i].fst)
        {
            cnt++;
            who = i;
        }
    }
    forn (i, sz(sons))
    {
        if (sons[i].snd && who == -1)
        {
            who = i;
        }
    }

    if (who != -1 && cnt <= 1 && sons[who].snd)
        res.fst = true;
    return res;
}

void solve (int n)
{
    vvi g(n);
    forn (i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    anst res = dfs(0, -1, g);
    cout << (res.fst ? "Second" : "First") << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
        solve(n);
}
