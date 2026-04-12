#include <bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;

int table[maxn] = {}, arr[maxn] = {};
int n, x, m, l, r;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x >> m;
    table[x] = 1; arr[1] = x;
    for(int i = 2; true; i++) {
        x = x * x % m;
        arr[i] = x;
        if(table[x]) {
            l = table[x];
            r = i;
            break;
        }
        table[x] = i;
    }
    // 2 4 0 0 0 0
    for(int i = 1; i <= r; i++) {
        arr[i] += arr[i - 1];
    }
    int ans = 0;
    if(n < l) {
        ans = arr[n];
    }
    else {
        n -= l;
        ans += arr[l];
        int cnt = n / (r - l);
        ans += cnt * (arr[r] - arr[l]);
        ans += arr[l + n % (r - l)] - arr[l];
    }
    cout << ans << '\n';
    return 0;
}
