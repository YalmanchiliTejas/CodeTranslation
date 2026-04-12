#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int n_max = 8;
int n,m,ans = 0;
vector<int> v[n_max];
vector<bool> seen;
void dfs(int pos)
{
    bool flag = true;
    for(int i = 0;i < n;i++)
    {
        if(!seen[i])
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        ans++;
        return;
    }
    for(int i = 0;i < v[pos].size();i++)
    {
        if(!seen[v[pos][i]])
        {
            seen[v[pos][i]] = true;
            dfs(v[pos][i]);
            seen[v[pos][i]] = false;
        }
    }
    return;
}
int main()
{
    cin >> n >> m;
    seen.resize(n,false);
    seen[0] = true;
    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0);
    cout << ans << "\n";

    return 0;
}