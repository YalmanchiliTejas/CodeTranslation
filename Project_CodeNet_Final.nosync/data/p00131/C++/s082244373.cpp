#include <iostream>

using namespace std;

int F[10][10];
int T[10][10];
int P[10];

bool check() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (T[i][j]) return false;
    return true;
}

bool solve(int c, int n) {
    for (int i = 0; i < 10; i++) {
        if (n & (1<<i)) {
            if (c-1 >= 0) T[c-1][i] = !T[c-1][i];
            if (i-1 >= 0) T[c][i-1] = !T[c][i-1];
            T[c][i]   = !T[c][i];
            if (i+1 < 10) T[c][i+1] = !T[c][i+1];
            if (c+1 < 10) T[c+1][i] = !T[c+1][i];
        }
    }
    P[c] = n;
    if (c == 9) return check();
    int next = 0;
    for (int i = 0; i < 10; i++) {
        if (T[c][i]) {
            next |= (1<<i);
        }
    }
    return solve(c+1, next);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        for (int i = 0; i < 10; i++) 
            for (int j = 0; j < 10; j++)
                cin >> F[i][j];
        for (int i = 0; i < (1<<10); i++) {
            for (int k = 0; k < 10; k++) for (int j = 0; j < 10; j++) T[k][j] = F[k][j];
            if (solve(0, i)) 
                break;
        }
        for (int i = 0; i < 10; i++) {
            cout << (P[i] & 1);
            for (int j = 1; j < 10; j++) {
                cout << ' ' << (P[i] & (1<<j) ? 1 : 0);
            }
            cout << endl;
        }
    }
    return 0;
}