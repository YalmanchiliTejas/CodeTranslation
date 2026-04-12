#include <bits/stdc++.h>
#define int long long
using namespace std;

int z(int n) {
    return (1LL << (n + 1)) - 3;
}
int p(int n) {
    return (1LL << n) - 1;
}

int ans(int n, int x) {
    if(x <= 0) return 0;
    if(n == 1) return 1;
    if((x - 1) < z(n - 1)) return ans(n - 1, x - 1);
    return p(n - 1) + 1 * ((x - 1 - z(n - 1)) > 0) + ans(n - 1, x - 2 - z(n - 1));
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin >> n >> x;
    ++n;
    cout << ans(n, x) << endl;
}
