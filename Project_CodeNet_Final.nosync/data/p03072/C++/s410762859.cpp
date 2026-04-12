#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << (x) << '\n';
typedef int64_t Int;
Int mod = 1e9+7;
Int INF = 1e18+7;

int main() {
    ios::sync_with_stdio(false);   
    Int n;
    cin >> n;
    vector<Int> h(n);
    for (Int i = 0; i < n; i++) cin >> h[i];
    Int ma = 0;
    Int res = 0;
    for (Int i = 0; i < n; i++) {
        if (ma <= h[i]) {
            res++;
            ma = h[i];
        }
    }
    dump(res);
    return 0;
}