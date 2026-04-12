#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;
int N, M;

int main()
{
    cin >> N >> M;
    Graph G(N+1);
    int b[N];

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        // 無向グラフ
        G[from].push_back(to);
        G[to].push_back(from);
    }
    for (int i = 0; i < N; i++) b[i] = i + 1;

    // すべての頂点の順列を探索
    int cnt = 0;
    int cv, nv;
    do {
        int i;
        if (b[0] != 1) continue;
        for (i = 0; i < N-1; i++) {
            cv = b[i];
            nv = b[i+1];
            auto exist = find(G[cv].begin(), G[cv].end(), nv);
            if (exist == G[cv].end()) break;
        }
        if (i == N-1) cnt++;
    } while (next_permutation(b, b + N));

    cout << cnt << endl;
}