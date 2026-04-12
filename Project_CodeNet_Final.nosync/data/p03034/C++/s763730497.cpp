#include "bits/stdc++.h"
using namespace std;
typedef long long li;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    li n;
    cin >> n;
    vector<li> ss(n);
    for (int i = 0; i < n; ++i) {
        cin >> ss[i];
    }

    li ans = 0;
    for (int d = 1; d < n; ++d) {
        li sum = 0;
        set<li> lvisit;
        for (int l = 0, r = n - 1; l < n && r >= 0; l += d, r -= d) {
            const li a = r;
            const li b = a - d;
            if (a <= 0 || b <= 0) {
                break;
            }
            lvisit.insert(l);
            if (lvisit.find(r) != lvisit.end()) {
                break;
            }
            sum += ss[l] + ss[r];
            ans = max(sum, ans);
        }
    }

    cout << ans << endl;

    return 0;
}