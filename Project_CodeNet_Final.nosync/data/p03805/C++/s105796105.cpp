#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, a, b, ans = 0;
    cin >> n >> m;
    vector<int> G[n];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    int un_vis = n;
    vector<bool> vis(n, false);
    stack<pair<int, bool>> s;
    s.push({0, false});
    bool debug = false;
    int tp;
    while (!s.empty())
    {
        tp = s.top().first;
        if (debug)
            cout << "Top: " << tp << endl;
        if (vis[tp])
        {
            while (!s.empty() and vis[s.top().first])
            {
                if (debug)
                    cout << "Pop1: " << s.top().first << " ";
                vis[s.top().first] = false;
                un_vis++;
                s.pop();
            }
            if (debug)
                cout << endl;

            if (s.empty())
                break;
            tp = s.top().first;
            if (debug)
                cout << "New Top: " << tp << endl;
        }

        vis[tp] = true;
        un_vis--;
        for (int i = 0; i < G[tp].size(); i++)
        {
            if (!vis[G[tp][i]])
            {
                if (debug)
                    cout << "Push: " << G[tp][i] << " ";
                s.push({G[tp][i], false});
            }
        }
        if (debug)
            cout << endl;

        if (un_vis == 0)
        {
            ans++;
            while (!s.empty() and vis[s.top().first])
            {
                if (debug)
                    cout << "Pop: " << s.top().first << " ";
                vis[s.top().first] = false;
                un_vis++;
                s.pop();
            }
            if (debug)
                cout << endl;
        }
    }
    cout << ans << endl;
}