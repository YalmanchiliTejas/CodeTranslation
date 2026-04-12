#include <iostream>
using namespace std;

const long long INF = 1LL << 60;

int N, a[3009];

long long dp[3009][3009];

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> a[i];

    for(int bit = 0; bit < N; bit++) {
        for(int l = 1; l + bit <= N; l++) {
            int r = l + bit;
            dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }

    cout << dp[1][N] << endl;

    return 0;
}