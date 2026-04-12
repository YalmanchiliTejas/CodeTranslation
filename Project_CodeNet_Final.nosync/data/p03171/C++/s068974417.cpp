#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[3005][3005];
signed main() {
    int N;
    cin >> N;
    vector<int>a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 1; i <= N; i++) {
        for(int j = 0; i+j <= N; j++) {
            int k = i+j;
            if((N-i)%2 == 0) {
                dp[j][k] = max(dp[j+1][k]+a[j],dp[j][k-1]+a[k-1]);
            }
            else {
                dp[j][k] = min(dp[j+1][k]-a[j],dp[j][k-1]-a[k-1]);
            }
        }
    }
    cout << dp[0][N] << endl;
}