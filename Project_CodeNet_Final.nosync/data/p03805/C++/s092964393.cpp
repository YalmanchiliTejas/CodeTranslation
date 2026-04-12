#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>(N));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = G[b][a] = 1;
    }
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        v[i] = i;

    int res = 0;
    do {
        if (v[0] != 0) break;
        bool flag = true;
        for (int i = 0; i < N - 1; i++) {
            if (G[v[i]][v[i + 1]] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) res++;
    } while (next_permutation(v.begin(), v.end()));

    cout << res << endl;
    return 0;
}