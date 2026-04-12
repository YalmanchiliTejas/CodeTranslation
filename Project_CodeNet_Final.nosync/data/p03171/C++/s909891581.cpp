#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
int a[3005];
ll dp[3005][3005][2];

int n;
ll go(int i, int j, int chance) {
    if(i > j) {
        return 0;
    }
    if(dp[i][j][chance] != -1e17) {
        return dp[i][j][chance];
    }
    ll ans;
    if(chance == 0) {
        ans = -1e17;;
        ans = max(ans, a[i] + go(i + 1, j, 1));
        ans = max(ans, a[j] + go(i, j - 1, 1));
    } else {
        ans = 1e17;
        ans = min(ans, go(i + 1, j, 0) - a[i]);
        ans = min(ans, go(i, j - 1, 0) - a[j]);
    }
    return dp[i][j][chance] = ans;
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dp[i][j][0] = -1e17;
            dp[i][j][1] = -1e17;
        }
    }
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    cout<<go(0, n - 1, 0);
}