#include <bits/stdc++.h>
using namespace std;

int N, M;
bool mp[10][10], d[10];

int dfs(int a) {
    bool all_visited = true;
    for (int i = 0; i < N; i++) {
        if (!d[i]) all_visited = false;
    }

    int mem = 0;
    if (all_visited) return 1;
    for (int i = 0; i < N; i++) {
        if (!mp[a][i]) continue;
        if (d[i]) continue;
        d[i] = true;
        mem += dfs(i);
        d[i] = false;
    }
    return mem;
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < 10; i++) d[i] = false;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        mp[a-1][b-1] = mp[b-1][a-1] = true;
    }
    
    d[0] = true;
    cout << dfs(0) << endl;
    return 0;
}