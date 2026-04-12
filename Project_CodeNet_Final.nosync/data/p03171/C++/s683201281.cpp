#include <iostream>
using namespace std;

int N, a[3009];

long long dp[3009][3009];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];

    for(int bit = 0; bit < N; bit++) {
        for(int l = 0; l + bit < N; l++) {
            int r = l + bit;
            dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }

    cout << dp[0][N - 1] << endl;

    return 0;
}