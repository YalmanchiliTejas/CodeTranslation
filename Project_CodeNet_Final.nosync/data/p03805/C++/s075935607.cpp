#include <bits/stdc++.h>

using namespace std;

// 別解（隣接行列の利用）
int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a;
    vector<int> b;
    vector<vector<int>> adjacencyMatrix(9, vector<int>(9, false));  // 隣接行列
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adjacencyMatrix.at(a - 1).at(b - 1) = adjacencyMatrix.at(b - 1).at(a - 1) = true;
    }

    // 考え方メモ
    // 前提：グラフの経路は頂点の並びで全パターン洗い出せる

    vector<int> permutation;
    for (int i = 0; i < N; i++) {
        permutation.push_back(i);
    }

    // 考え方メモ
    // 具体例：
    // case1: (0, 1, 2) -> (0, 1) = (a0, b0) or (a1, b1) or (a2, b2)
    // case2: (0, 2, 1) -> (0, 2) = (a0, b0), (2, 1) = (a1, b1)
    int allPathClearCount = 0;
    do {
        if (permutation.at(0) != 0) break;  // 0始まり以外無視

        bool isOk = true;
        for (int i = 0; i < N - 1; i++) {
            int num = permutation.at(i);
            int nextNum = permutation.at(i + 1);
            if (!adjacencyMatrix.at(num).at(nextNum)) {
                isOk = false;
            }
        }
        if (isOk) {
            allPathClearCount++;
        }
    } while (next_permutation(permutation.begin(), permutation.end()));

    cout << allPathClearCount << endl;

    return 0;
}