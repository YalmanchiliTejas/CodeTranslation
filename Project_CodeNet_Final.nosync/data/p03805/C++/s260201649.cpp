#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX_N = 9;
vector<int> v[MAX_N];
int n, m;
int ans = 0;

void dfs(vector<bool> fl, int id)
{
    bool ch = true;
    for (int i = 1; i < fl.size(); i++)
    {
        ch &= fl[i];
    }
    if (ch)
    {
        ans++;
        return;
    }
    for (int i = 0; i < v[id].size(); i++)
    {
        if (fl[v[id][i]] == false)
        {
            fl[v[id][i]] = true;
            dfs(fl, v[id][i]);
            fl[v[id][i]] = false;
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    vector<bool> flag(n + 1);
    for (int i = 0; i <= n; i++)
    {
        flag[i] = false;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    flag[1] = true;
    dfs(flag, 1);
    cout << ans << endl;
    return 0;
}