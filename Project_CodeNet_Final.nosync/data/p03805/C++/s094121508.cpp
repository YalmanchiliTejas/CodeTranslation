#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int v[N];
    for (int i=0; i<N; i++) v[i] = i;
    int adj_mat[N][N];
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            adj_mat[i][j] = 0;
        }
    }
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;
    }
    int ans = 0;
    bool perm_flag = true;
    while (perm_flag) {
        bool flag = true;
        for (int i=0; i<N-1; i++) {
            flag = flag && (adj_mat[v[i]][v[i+1]] == 1);
        }
        if (flag) ans++;
        perm_flag = next_permutation(v+1, v+N);
    }
    cout << ans << endl;
}