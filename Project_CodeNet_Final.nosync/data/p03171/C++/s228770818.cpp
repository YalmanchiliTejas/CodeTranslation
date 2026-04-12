#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long dp[2][N][N];
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < 2; k++) {
            dp[k][i][i] = arr[i];
            if (k == 1) dp[k][i][i] *= -1;
        }
    }
    
    for (int i = N - 1; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            for (int k = 0; k < 2; k++) {
                long long n1 = dp[k^1][i][j-1];
                long long n2 = dp[k^1][i+1][j];
                if (k == 0) {
                    dp[k][i][j] = max(n1+arr[j], n2+arr[i]);
                } else {
                    dp[k][i][j] = min(n1-arr[j], n2-arr[i]);
                }
            }
        }
    }

    cout << dp[0][0][N-1] << "\n";
}

