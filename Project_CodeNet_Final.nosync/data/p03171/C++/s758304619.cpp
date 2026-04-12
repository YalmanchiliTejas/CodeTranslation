#include <vector>
#include <iostream>

using namespace std;

typedef long long LL;

int main(int argc, const char * argv[]) {
//    freopen("4.in", "r", stdin);
    int n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0;i < n; i++) {
        cin >> a[i];
    }
    vector<vector<LL>> dp(n, vector<LL>(n));
    for (int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            dp[i][i+len-1] = max(a[i] - dp[i+1][i+len-1], a[i+len-1] - dp[i][i+len-2]);
        }
    }
    
//    for (int i = 0;i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
//
    cout << dp[0][n-1] << endl;
    
    return 0;
}
