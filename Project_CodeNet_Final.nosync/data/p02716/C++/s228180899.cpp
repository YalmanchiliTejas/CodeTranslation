#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector<ll>a(n+5),dp(n+5), sum(n+5);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = a[i];
        if(i > 2) sum[i] += sum[i-2];
    }
    for(int i = 2; i <= n; i++) 
        dp[i] = max((i&1?dp:sum)[i-1], dp[i-2] + a[i]);
    cout << dp[n] << endl;
    return 0;
}

