/*
░░░░░░░▄▀▀▀▀▀▀▀▄▄░░░░░░
░░░░░░▐░░░▄▄▄▄▄░ ▀▀▄
░░░░░▐░$░▐▀░░░░▀▀▀▀▄▀
░░░░░▌░░▐░░░░░░░░░░▄▄
░░░░▐░░░░▀▄▄▄▄▄▄▀▀▀░▄▀
░░░░▌▒░▒░▒░▒░░░▄▄▄▀▀
░░░░▌▒▒░▒▒▒▒▄▄▀▀
░░░▐░░▒▒▒▄▀▀░░░░░░░
░░░▐░▒▒▒▐░░░░░░░░░
░░░▐▒▒▒▒▌░░░░░░░░
░░░▐▒▒▒░▐░░░░░░░░░▄▀▄
░░░▐▒▒░▒▐▄▄▀▀▀▀▄▄▄▀░▌
░░░▐░▒▒░▄▄▄▄▀▀▄▄▄▄▄▀
░░▐▒▒▄▒▒▀▄▄▄▄▄▀░░░▄▌░░
░░▌▒▐░▀▀▄▄▄▄▄▄▄▀▀▀░░░░
░▐▒▒▌░░░░░░░░░░░░░ 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

int deg[N];
int cnt[N];
int kek[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <pair <int, int> > e;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e.push_back({u, v});
        deg[u]++;
        deg[v]++;
    }
    for (auto c : e)
    {
        int u = c.first, v = c.second;
        if (deg[v] == 1)
        {
            cnt[u]++;
        }
        if (deg[u] == 1)
        {
            cnt[v]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] > 1)
        {
            cout << "First\n";
            return 0;
        }
        else
        {
            if (cnt[i] == 1)
            {
                kek[i] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = 0;
    }
    for (auto c : e)
    {
        int u = c.first, v = c.second;
        cnt[u] += kek[v];
        cnt[v] += kek[u];
    }
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 1)
        {
            continue;
        }
        if (!kek[i] && cnt[i] == deg[i])
        {
            cout << "First\n";
            return 0;
        }
    }
    if (n % 2 == 0)
    {
        cout << "Second\n";
    }
    else
    {
        cout << "First\n";
    }
}
