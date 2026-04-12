#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 8;
const int MAX_M = 28;

int main() {
    // input
    int N, M, a[MAX_M], b[MAX_M];
    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> a[i] >> b[i];

    // initialize path
    int path[MAX_N + 1][MAX_N + 1];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) path[i][j] = 0;
    }
    for (int i = 0; i < M; i++) {
        path[a[i]][b[i]] = 1;
        path[b[i]][a[i]] = 1;
    }

    // initialize permutation
    int perm[MAX_N];
    for (int i = 0; i < N; i++) perm[i] = i + 1;

    int count_path = 0;
    do {
        bool exist_path = true;
        for (int i = 1; i < N; i++) {
            if (path[perm[i-1]][perm[i]] == 0) exist_path = false;  
        }
        if (exist_path) count_path++;
    } while (next_permutation(perm + 1, perm + N));

    cout << count_path << endl;
    return 0;
}