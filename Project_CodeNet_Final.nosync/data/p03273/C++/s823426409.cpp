#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

const int CMax = 102;

int n, m, C[CMax], D[CMax];
string S[CMax];
long long sum;

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        cin >> S[i];
        for (int j = 0; j < m; j++) {
            if (S[i][j] == '#') {
                C[i]++;
                D[j]++;
            }
        }
    }

    bool tik = false;

    for (int i = 0; i < n; i++) {
        tik = false;
        for (int j = 0; j < m; j++) {
            if (C[i] > 0 && D[j] > 0) {
                cout << S[i][j];
                tik = true;
            }
        }
        if (tik) cout << endl;
    }
}
