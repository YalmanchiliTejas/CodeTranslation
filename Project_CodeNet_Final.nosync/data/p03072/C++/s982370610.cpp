#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n; cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    int ma = h[0];
    int ans = 1;

    for (int i = 1; i < n; ++i) {
        if (ma <= h[i]) {
            ++ans;
            ma = h[i];
        }
    }

    cout << ans << endl;
}