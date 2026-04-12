#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long
#define endl '\n'

signed main() {
    int n,k;
    cin >> n >> k;

    int ans = 0;
    for(int i = k + 1; i <= n; i++){
        int cnt = i - k;
        int d = n / i;
        int m = n % i;
        ans += cnt * d + max((k == 0) ? m - k : m - k + 1, 0LL);
    }
    cout << ans << endl;
}