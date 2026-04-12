#include <iostream>
using namespace std;

#define MAX_N 8
bool used[MAX_N+1] = {0};
int perm[MAX_N+1];
int cmat[MAX_N+1][MAX_N+1];
int count = 0;

bool check_onepath(int n) {
    int p = 1;
    bool flag = false;
    for (int i = 2; i < n+1; i++) {
        if (cmat[p][perm[i]] < 1) break;
        p = perm[i];
        if (i == n) flag = true;
    }
    return flag;
}

int permutation(int pos, int n) {
    if (pos == n+1) {
        // for (int i = 1; i < n+1; i++) cout << perm[i];
        // cout << endl;
        if (check_onepath(n)) count++;
        return 0;
    }
    for (int i = 2; i < n+1; i++) {
        if (!used[i]) {
            perm[pos] = i;
            used[i] = true;
            permutation(pos+1, n);
            used[i] = false;
        }
    }
    return 0;
}


int main() {
    fill((int*)cmat, (int*)(cmat+MAX_N+1), 0);
    // (N-1)! 通りの通り方を全部試す (2<=N<=8)
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        cmat[u][v] = 1;
        cmat[v][u] = 1;
    }
    // 順列
    perm[1] = 1;
    used[1] = true;
    if (N == 1) count++;
    else permutation(2, N);
    cout << count << endl;
    return 0;
}
