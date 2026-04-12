#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int n, m, Assigned[N];
int Visited[N], t=0;
vector<int> a[N];

bool visit(int u) {
    if (Visited[u]!=t)
        Visited[u]=t;
    else
        return false;

    for (int i=0; int v=a[u][i]; i++)
    if (!Assigned[v] || visit(Assigned[v])) {
        Assigned[v]=u;
        return true;
    }
    return false;
}

main() {
    scanf("%d", &n);
    int x, y;
    for(int i = 1; i <= n-1; ++i) {
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i=1; i<=n; i++)
        a[i].push_back(0);

    int Count = 0;
    for (int i=1; i<=n; i++) {
        t++;
        Count += visit(i);
    }
    cout << (Count == n ? "Second": "First");
}
