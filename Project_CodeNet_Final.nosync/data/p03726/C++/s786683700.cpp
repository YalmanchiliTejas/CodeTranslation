#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;
int n, i, x, y;
bitset<Nmax> erased, used;
vector<int> v[Nmax];

bool dfs(int node, int dad)
{
    used[node] = 1;
    for(auto it : v[node])
        if(!used[it] && !dfs(it, node)) return 0;

    if(!erased[node])
    {
        if(erased[dad] || !dad) return 0;
        erased[dad] = erased[node] = 1;
    }

    return 1;
}

int main()
{
   /// freopen("input", "r", stdin);
    cin.sync_with_stdio(false);

    cin >> n;
    for(i=1; i<n; ++i)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    cout << (dfs(1, 0) ? "Second" : "First") << '\n';

    return 0;
}
