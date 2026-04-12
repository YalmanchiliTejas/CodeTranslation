#include <bits/stdc++.h>
using namespace std;

vector < int > G[9];
int N, M;

int dfs(int v, int bit)
{
    int ret = 0;
    if(bit == (1 << N) - 1) {
        return (1);
    }
    for(int i = 0; i < G[v].size(); i++) {
        int u = G[v][i];
        if(((bit >> u) & 1) == 0) {
            ret += dfs(u, bit | (1 << u));
        }
    }
    return (ret);
}
int main()
{

    cin >> N >> M;

    while(M--) {
        int a, b;
        cin >> a >> b; --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << dfs(0, 1) << endl;

    return (0);
}
