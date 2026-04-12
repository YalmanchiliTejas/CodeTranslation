#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    ll a[55] = {}, z = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    while (1) {
        for (int i = 0; i < n; i++) if (a[i] >= n) {
            for (int j = 0; j < n; j++) if (j != i) a[j] += a[i] / n;
            z += a[i] / n;
            a[i] %= n;
        }
        bool y = 0;
        for (int i = 0; i < n; i++) if (a[i] >= n) y = 1;
        if (!y) break;
    }
    cout << z;
}
