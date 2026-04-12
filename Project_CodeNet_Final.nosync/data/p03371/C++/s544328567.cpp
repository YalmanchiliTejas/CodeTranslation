#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = L_INF;

    for (ll d = 0; d <= 300000; d++) {
        ll t = A * max(X - d / 2, 0LL) + B * max(Y - d / 2, 0LL) + C * d;
        ans = min(ans, t);
    }

    cout << ans << "\n";

    return 0;
}