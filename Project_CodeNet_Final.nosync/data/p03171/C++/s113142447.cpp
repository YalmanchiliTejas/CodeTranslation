#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int N = 5000 + 5;
 
ll dp[N][N]; 
 
int main() { 
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dp[i][j] = a[i];
            else dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }
    cout << dp[1][n] << '\n';
}
