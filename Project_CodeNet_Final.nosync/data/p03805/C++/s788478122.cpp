#include <bits/stdc++.h>
using namespace std;

int n, m;
int edge[11][11];

int isOn(int bitmask, int i)
{
    if ((bitmask & (1 << i)) != 0) {
        return 1;
    }
    return 0;
}

int setBit(int bitmask, int i)
{
    bitmask = (bitmask | (1 << i));
    return bitmask;
}

int go(int u, int bitmask)
{
    if (bitmask == ((1 << n) - 1)) {
        return 1;
    }
    int i, res = 0;
    for (i = 1; i <= n; i++) {
        if (isOn(bitmask, i) == 0 && edge[u][i] == 1) {
            res += go(i, setBit(bitmask, i));
        }
    }
    return res;
}

int main( )
{
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edge[u][v] = 1;
        edge[v][u] = 1;
    }
    cout << go(0, 1) << '\n';
    return 0;
}

