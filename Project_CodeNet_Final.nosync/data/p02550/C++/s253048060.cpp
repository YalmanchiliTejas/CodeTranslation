
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

#define INF ((1<<30)-1)
#define LLINF (1LL<<60)
#define EPS (1e-10)

ll f(ll x, ll m) {
    return x % m;
}

ll sums[201010], vis[202020];

int main() {
    ll N, X, M;
    cin >> N >> X >> M;

    if (N <= 1000000) {
        ll sum = X;
        ll A = f(X * X, M);
        rep(i, N-1) {
            sum += A;
            A = f(A * A, M);
        }
        cout << sum << endl;
    }
    else {
        ll ans = 0, cnt = 0;
        fill(vis, vis+M, -1);
        while (N > 0) {
            if (vis[X] >= 0) {
                // 一度見たところ
                ll len = cnt - vis[X];
                ll tmpAns = ans;
                ans += (tmpAns - sums[vis[X]]) * (N / len);
                N %= len;
                break;
            }

            if (N > 0) {
                vis[X] = cnt++;
                ans += X;
                sums[cnt] = ans;
                X = f(X * X, M);
                N--;
            }
        }
        while (N > 0) {
            if (N > 0) {
                ans += X;
                X = f(X * X, M);
                N--;
            }
        }

        cout << ans << endl;
    }
}
