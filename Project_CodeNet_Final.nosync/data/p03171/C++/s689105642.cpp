#include <bits/stdc++.h>
#define int long long
#define maxn 3005
using namespace std;

int arr[maxn], dp[maxn][maxn];
int n;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i][i] = (n & 1) ? arr[i] : -arr[i];
    }
    for(int len = 2; len <= n; len++) {
        int flag = (len & 1) == (n & 1) ? 1 : -1;
        for(int i = 1; i + len - 1 <= n; i++) {
            int l = i, r = i + len - 1;
            int A = dp[i + 1][r] + flag * arr[l];
            int B = dp[i][r - 1] + flag * arr[r];
            if(flag == 1) { // Taro
                dp[l][r] = A > B ? A : B;
            }
            else { // Jiro
                dp[l][r] = A < B ? A : B;
            }
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}
