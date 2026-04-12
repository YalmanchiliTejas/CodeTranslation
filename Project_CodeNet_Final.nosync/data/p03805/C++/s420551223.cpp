#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a;
    vector<int> b;
    for (int i = 0; i < M; i++) {
        int tmpA, tmpB;
        cin >> tmpA >> tmpB;
        a.push_back(tmpA - 1);
        b.push_back(tmpB - 1);
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
        int pathClearCount = 0;
        if (permutation.at(0) != 0) break;

        for (int i = 0; i < N - 1; i++) {
            int num = permutation.at(i);
            int nextNum = permutation.at(i + 1);
            for (int j = 0; j < M; j++) {
                if ((a.at(j) == num && b.at(j) == nextNum) || (a.at(j) == nextNum && b.at(j) == num)) {
                    pathClearCount++;
                }
            }
        }
        if (pathClearCount == N - 1) {
            allPathClearCount++;
        }
    } while (next_permutation(permutation.begin(), permutation.end()));

    cout << allPathClearCount << endl;

    return 0;
}