#include <cstring>
#include <iostream>
using namespace std;

int N;
int A[3010];
long dp[2][3010][3010];


long calcdp(bool p, int i, int j){
    if (dp[p][i][j] != LONG_MAX) {
        return dp[p][i][j];
    }

    if (i == j-1) {
        if (p) {
            dp[p][i][j] = A[i];
        } else {
            dp[p][i][j] = -A[i];
        }
        return dp[p][i][j];
    } else {
        if (p) {
            dp[p][i][j] = max(calcdp(not(p), i+1, j) + A[i], calcdp(not(p), i, j-1) + A[j-1]);
        } else {
            dp[p][i][j] = min(calcdp(not(p), i+1, j) - A[i], calcdp(not(p), i, j-1) - A[j-1]);
        }
        return dp[p][i][j];
    }
}


int main() {
    cin >> N;
    for (int i = 0; i < N; i++){
        int a; cin >> a;
        A[i] = a;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3010; j++) {
            for (int k = 0; k < 3010; k++) {
                dp[i][j][k] = LONG_MAX;
            }
        }
    }

    cout << calcdp(true, 0, N) << endl;

    return 0;
}