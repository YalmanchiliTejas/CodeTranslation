#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int S[500], T[500];
ull U[500], V[500];
int A[64][500][500];
ull a[500][500];
bool NG1[500], NG2[500];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> S[i];
    for (int i = 0; i < N; i++)
        cin >> T[i];
    for (int i = 0; i < N; i++)
        cin >> U[i];
    for (int i = 0; i < N; i++)
        cin >> V[i];
    fill((int *)A, (int *)(A + 64), -1);
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < N; j++) {
            int b = (U[j] >> i) & 1;
            if ((S[j] == 0 && b == 0) || (S[j] == 1 && b == 1))
                continue;
            for (int k = 0; k < N; k++) {
                A[i][j][k] = b;
            }
        }
        for (int j = 0; j < N; j++) {
            int b = (V[j] >> i) & 1;
            if ((T[j] == 0 && b == 0) || (T[j] == 1 && b == 1))
                continue;
            for (int k = 0; k < N; k++) {
                if (A[i][k][j] == (b ^ 1)) {
                    cout << -1 << endl;
                    return 0;
                }
                A[i][k][j] = b;
            }
        }
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                int b1 = (U[j] >> i) & 1;
                int b2 = (V[k] >> i) & 1;
                if ((S[j] == 0 && T[k] == 0 && b1 == 0 && b2 == 0)) {
                    A[i][j][k] = 0;
                }
                if ((S[j] == 1 && T[k] == 1 && b1 == 1 && b2 == 1)) {
                    A[i][j][k] = 1;
                }
            }
        }
        memset(NG1, 0, sizeof(NG1));
        memset(NG2, 0, sizeof(NG2));
        for (int j = 0; j < N; j++) {
            int b = (U[j] >> i) & 1;
            if ((S[j] == 0 && b == 1) || (S[j] == 1 && b == 0))
                continue;
            NG1[j] = 1;
            for (int k = 0; k < N; k++) {
                if (A[i][j][k] == b) {
                    NG1[j] = 0;
                    break;
                }
            }
            if (!NG1[j]) {
                for (int k = 0; k < N; k++) {
                    if (A[i][j][k] == -1) {
                        A[i][j][k] = 2;
                    }
                }
            }
        }
        for (int j = 0; j < N; j++) {
            int b = (V[j] >> i) & 1;
            if ((T[j] == 0 && b == 1) || (T[j] == 1 && b == 0))
                continue;
            NG2[j] = 1;
            for (int k = 0; k < N; k++) {
                if (A[i][k][j] == b) {
                    NG2[j] = 0;
                    break;
                }
            }
            if (!NG2[j]) {
                for (int k = 0; k < N; k++) {
                    if (A[i][k][j] == -1) {
                        A[i][k][j] = 2;
                    }
                }
            }
        }
        vector<int> row, col;
        for (int j = 0; j < N; j++) {
            if (!NG1[j])
                continue;
            int b = (U[j] >> i) & 1;
            for (int k = 0; k < N; k++) {
                if (A[i][j][k] == b || A[i][j][k] == 2) {
                    A[i][j][k] = b;
                    NG1[j] = 0;
                }
            }
            if (NG1[j])
                row.push_back(j);
        }
        for (int j = 0; j < N; j++) {
            if (!NG2[j])
                continue;
            int b = (V[j] >> i) & 1;
            for (int k = 0; k < N; k++) {
                if (A[i][k][j] == b || A[i][k][j] == 2) {
                    A[i][k][j] = b;
                    NG2[j] = 0;
                }
            }
            if (NG2[j])
                col.push_back(j);
        }
        if ((row.size() >= 1 && col.size() <= 1) ||
            (row.size() <= 1 && col.size() >= 1)) {
            cout << -1 << endl;
            return 0;
        }
        int start = 0;
        for (int r : row) {
            int x = start;
            for (int c : col) {
                A[i][r][c] = x;
                x ^= 1;
            }
            start ^= 1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ull a = 0;
            for (int k = 0; k < 64; k++) {
                if (A[k][i][j])
                    a |= (1ULL << k);
            }
            cout << a << " ";
        }
        cout << endl;
    }
}