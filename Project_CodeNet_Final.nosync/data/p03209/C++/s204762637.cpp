#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 10007;
const int inf = 101234567;

ll a[51], p[51];

ll f(ll N, ll X) {
    if (N == 0) {
        if (X <= 0) {
            return 0;
        } else {
            return 1;
        }
    } else if (X <= 1+a[N-1]) {
        return f(N-1, X-1);
    } else {
        return p[N-1] + 1 + f(N-1, X-2-a[N-1]);
    }
}

int main() {
    ll N, X;
    ll ans;
    cin >> N >> X;
    a[0] = 1;
    p[0] = 1;
    for (int i = 1; i < 51; i++) {
        a[i] = a[i-1]*2+3;
        p[i] = p[i-1]*2+1;
    }
    ans = f(N, X);

    cout << ans << endl;
}
