#include <iostream>
using namespace std;

int M, N;
char A[50][51], B[50][51];
bool E[10][10];

int c = 0;
bool passed[10];

void dfs(int idx) {
    passed[idx] = true;
    bool f = true;
    for (int i = 0; i < N; i++) {
        if(!passed[i]) {
            f = false;
            if (E[idx][i]) {
                E[idx][i] = E[i][idx] = false;
                dfs(i);
                E[idx][i] = E[i][idx] = true;
            }
        }
    }
    if (f) c++;
    passed[idx] = false;
}

void solve() {
    for (int i = 0; i < N; i++) passed[i] = false;
    dfs(0);
    cout << c << endl;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        E[v1][v2] = E[v2][v1] = true;
    }

    solve();
}