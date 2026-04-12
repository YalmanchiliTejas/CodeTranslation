#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, k;

    cin >> n >> k;

    ll res = 0;

    for(int b = 1;b <= n;b++) {
        for(int p = 0;p * b <= n;p++) {
            int l = 1;
            int r = n;
            l = max(l, p * b + k);
            r = min(r, b * p + b - 1);
            if(l <= r) {
                res += r - l + 1;
            }
        }
    }

    cout << res << "\n";

    return 0;
}
