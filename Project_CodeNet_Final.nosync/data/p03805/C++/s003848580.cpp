#include <bits/stdc++.h>
using namespace std;

const int N = 10;

vector <int> vc[N];
bool vis[N];
int n, m;

int traverse (int u, int total) {

    vis[u] = true;

    if (total == n) {
        total --;
        return 1;
    }

    int way = 0;
    for (auto v : vc[u]) {
        if (not vis[v]) {
            total ++;
            way += traverse (v, total);
            vis[v] = false;
            total --;
        }
    }

    return way;
}

int main () {

    scanf ("%d %d", &n, &m);

    for (int i = 1; i <= m; i ++) {
        int u, v;
        scanf ("%d %d", &u, &v);
        vc[u].push_back(v); vc[v].push_back(u);
    }

    printf ("%d\n", traverse (1, 1));

    return 0;
}
