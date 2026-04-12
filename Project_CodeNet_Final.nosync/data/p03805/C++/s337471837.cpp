#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    bool table[15][15] {};
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        table[a][b] = true;
        table[b][a] = true;
    }

    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i + 1;

    int ans = 0;
    do {
        if (v[0] != 1) break;
        bool check = true;
        for (int i = 1; i < N; i++) {
            if (!table[v[i]][v[i - 1]]) check = false;
        }
        if (check) ans++;
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}