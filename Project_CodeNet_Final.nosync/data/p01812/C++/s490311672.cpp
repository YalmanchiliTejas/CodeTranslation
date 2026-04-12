#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int M = 1000000007;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> d(m);
    vector<int> ind(n, -1);
    for (int i = 0; i < m; ++i) {
        cin >> d[i];
        --d[i];
        ind[d[i]] = i;
    }
    vector<vector<int>> edge(m, vector<int>(k, -1));
    for (int i = 0; i < n; ++i) {
        if (ind[i] == -1) {
            for (int j = 0; j < k; ++j)
                scanf("%*d");

            continue;
        }
        for (int j = 0; j < k; ++j) {
            int a;
            cin >> a;
            --a;
            edge[ind[i]][j] = ind[a];
        }
    }
    vector<int> c(1 << m, M);
    queue<int> q;
    q.push((1 << m) - 1);
    c[(1 << m) - 1] = 0;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int i = 0; i < k; ++i) {
            int nex = 0;
            for (int j = 0; j < m; ++j)
                if (((p >> j) & 1) && edge[j][i] != -1)
                    nex |= 1 << edge[j][i];

            if (c[nex] > c[p] + 1) {
                c[nex] = c[p] + 1;
                q.push(nex);
            }
        }
    }
    cout << c[0] << "\n";
    return 0;
}