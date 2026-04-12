#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 3005;
int a[maxN], n;
vector<vector<ll>> dp(maxN, vector<ll>(maxN, 0));
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int L = n-1; L >= 0; L--) {
        for(int R = L; R < n; R++) {
            if (R == L) {
                dp[L][R] = a[L];
            } else {
                dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1]);
            }
        }
    }
    cout << dp[0][n-1];
    return 0;
}
