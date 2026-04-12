#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

Int INF = 1e18;
Int mod = 1e9+7;
//Int mod = 998244353;

int main() {
    while (true) {
        Int n;
        cin >> n;
        if (n == 0) break;
        vector<Int> v(n);
        for (Int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(all(v));
        Int sum = 0;
        for (Int i = 1; i < n - 1; i++) {
            sum += v[i];
        }
        dump(sum / (n - 2));
    }
    return 0;
}

