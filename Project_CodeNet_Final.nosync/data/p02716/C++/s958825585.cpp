#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long

const int N = 200009, inf = 1000000000000000000;
int n, a[N];
int dp[N][6];

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j < 6; ++j) {
            dp[i][j] = -inf;
        }
    }
    dp[0][0] = 0;

    for(int i = 0; i < n; ++i) {
        int cur = a[i];
        dp[i+1][0] = dp[i][1];
        dp[i+1][1] = dp[i][0] + cur;
        dp[i+1][2] = max(dp[i][3], dp[i][0]);
        dp[i+1][3] = dp[i][2] + cur;
        dp[i+1][4] = max(dp[i][5], dp[i][2]);
        dp[i+1][5] = dp[i][4] + cur;
    }

    if(n%2) {
        vector<int> cands = {dp[n][2], dp[n][3], dp[n][4], dp[n][5]};
        cout << *max_element(cands.begin(), cands.end()) << '\n';
    } else {
        vector<int> cands = {dp[n][0], dp[n][1], dp[n][2], dp[n][3]};
        cout << *max_element(cands.begin(), cands.end()) << '\n';
    }
    
    return 0;
}
