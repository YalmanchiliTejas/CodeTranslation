
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, ans, t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (t >= m) {
            m = t;
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}

