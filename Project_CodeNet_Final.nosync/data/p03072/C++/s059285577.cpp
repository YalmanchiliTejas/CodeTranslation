#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    int n, ans = 1;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (int i = 1; i < n; i++) {
        bool flag = true;
        for (int k = i - 1; k >= 0; k--) {
            if (h[i] < h[k]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
