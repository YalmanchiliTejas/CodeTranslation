#include <iostream>
using namespace std;
typedef long long ll;
const int N = 3010;
ll dp[N][N];
ll seq[N];
int n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> seq[i];
        if(n % 2) {
            dp[i][i] = seq[i];
        } else dp[i][i] = -seq[i]; 
    }
    for(int len = 1; len < n; len ++) {
        for(int i = 1; i + len <= n; i ++) {
            int j = i + len;
            if((n - len - 1) % 2 == 0) {
                dp[i][j] = max(dp[i][j-1] + seq[j], dp[i+1][j] + seq[i]);
            } else {
                dp[i][j] = min(dp[i][j-1] - seq[j], dp[i+1][j] - seq[i]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}