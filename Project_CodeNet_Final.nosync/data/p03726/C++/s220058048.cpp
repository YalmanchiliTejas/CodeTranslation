#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <queue>

using namespace std;

const int INF = 1000000000;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void out(int x) {
     if (x == 1)
        cout << "First\n";
     if (x == 2)
        cout << "Second\n";
     cout.flush();
     cin >> x;
     exit(0);
}

int n;
vector<vector<int> > gr;
vector<int> kol;

void dfs(int v, int pr) {
    kol[v] = 1;
    int k = 0;
    for (int i = 0; i < (int)gr[v].size(); ++i) {
        int nv = gr[v][i];
        if (nv == pr)
           continue;
        dfs(nv, v);
        kol[v] += kol[nv];
        k += (kol[nv]&1);
    }
    if (pr >= 0)
       k += ((n - kol[v])&1);
    if (k >= 2)
       out(1);
}

int main() {
    scanf("%d", &n);
    gr.assign(n, vector<int>());
    for (int i = 1; i < n; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        --v1;
        --v2;
        gr[v2].push_back(v1);
        gr[v1].push_back(v2);
    }
    if (n&1)
       out(1);
    kol.assign(n, 0);
    dfs(0, -1);
    out(2);
    return 0;
}
