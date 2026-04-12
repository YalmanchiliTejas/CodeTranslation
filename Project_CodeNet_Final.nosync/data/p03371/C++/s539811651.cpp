#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

#define INF ((1<<30)-1)
#define LLINF (1LL<<60)
#define EPS (1e-10)

int main() {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = LLINF;
    for (int i = 0; i <= X; ++i) {
        ll tmp = (i * A) + (X - i) * 2LL*C;
        ll tmpY = Y - (X - i);
        if (tmpY > 0) {
            if (B < 2*C) tmp += tmpY * B;
            else tmp += 2*C * tmpY;
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}
