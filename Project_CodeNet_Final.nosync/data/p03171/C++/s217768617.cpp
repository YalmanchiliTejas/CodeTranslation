#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int MSIZE = 3003;

long long dp[MSIZE][MSIZE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int * arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int len = 1; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            if (l == r) {
                dp[l][r] = arr[l];
            } else {
                if (len & 1) {
                    dp[l][r] = max(
                                arr[l] + dp[l + 1][r],
                                arr[r] + dp[l][r - 1]
                            );
                } else {
                    dp[l][r] = min(
                                dp[l + 1][r] - arr[l],
                                dp[l][r - 1] - arr[r]
                            );
                }
            }
        }
    }

    cout << ((n & 1) ? dp[0][n - 1] : -dp[0][n - 1]) << endl;

}