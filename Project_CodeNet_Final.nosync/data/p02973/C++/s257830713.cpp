#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, ans, mina, maxa;
int a[MAXN], dp[MAXN];

int main(){
    cin >> n;
    for (int i = 0;i < n;i ++) cin >> a[i];
    for (int i = 0;i < n;i ++) dp[i] = INF;
    reverse(a, a + n);
    dp[++ ans] = a[0];
    for (int i = 1;i < n;i ++){
        if (a[i] >= dp[ans]) dp[++ ans] = a[i];
        else *upper_bound(dp + 1, dp + ans + 1, a[i]) = a[i];
    }
    cout << ans << endl;
    return 0;
}