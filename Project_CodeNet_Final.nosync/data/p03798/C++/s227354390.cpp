#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    vector<vector<bool>> A(4, vector<bool>(N, false));
    A[0][0] = 1, A[0][1] = 1, A[0][2] = 1;
    A[1][0] = 0, A[1][1] = 1, A[1][2] = 1;
    A[2][0] = 1, A[2][1] = 1, A[2][2] = 0;
    A[3][0] = 0, A[3][1] = 1, A[3][2] = 0;
    for (int P = 0; P < 2; P++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 2; j < N - 1; j++) {
                if ((P && s[j] == 'o' && !A[i][j]) ||
                    (P && s[j] == 'x' && A[i][j]) ||
                    (!P && s[j] == 'o' && A[i][j]) ||
                    (!P && s[j] == 'x' && !A[i][j])) {
                    A[i][j + 1] = A[i][j - 1];
                } else {
                    A[i][j + 1] = !(A[i][j - 1]);
                }
            }
            bool check = true;
            for (int j = 0; j < N; j++) {
                if (((P && s[j] == 'o' && !A[i][j]) ||
                     (P && s[j] == 'x' && A[i][j]) ||
                     (!P && s[j] == 'o' && A[i][j]) ||
                     (!P && s[j] == 'x' && !A[i][j])) &&
                    A[i][(N + j - 1) % N] != A[i][(N + j + 1) % N]) {
                    check = false;
                    break;
                } else if (((P && s[j] == 'x' && !A[i][j]) ||
                            (P && s[j] == 'o' && A[i][j]) ||
                            (!P && s[j] == 'x' && A[i][j]) ||
                            (!P && s[j] == 'o' && !A[i][j])) &&
                           A[i][(N + j - 1) % N] == A[i][(N + j + 1) % N]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int k = 0; k < N; k++) {
                    if ((!P && A[i][k]) || (P && !A[i][k])) {
                        cout << 'S';
                    } else {
                        cout << 'W';
                    }
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}
