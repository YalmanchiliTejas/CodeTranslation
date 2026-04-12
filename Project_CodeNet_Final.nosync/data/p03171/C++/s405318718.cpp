#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector <vector <long long int> > dp(n, vector <long long int> (n, 0));
    dp[n - 1][n - 1] = a[n - 1];

    for (int l = n - 2; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }
    
    cout << dp[0][n - 1] << '\n';

    return 0;
}