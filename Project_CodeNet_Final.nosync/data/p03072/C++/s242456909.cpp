#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int &x : a) cin >> x;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool ok = 1;
        for (int j = 0; j < i; j++) {
            ok &= (a[j] <= a[i]);
        }
        ans += ok;
    }
    cout << ans << '\n';
    return 0;
}
