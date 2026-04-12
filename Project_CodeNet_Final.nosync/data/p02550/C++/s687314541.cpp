#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 998244353;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, X, M;
    cin >> N >> X >> M;

    ll ans = 0;

    vector<bool> seen(M + 1);
    ll now = X;
    seen[X] = true;
    while (N) {
        N--;
        ans += now;
        now *= now;
        now %= M;
        if (seen[now]) {
            break;
        }
        seen[now] = true;
    }

    ll tmp = now;
    ll csum = 0, csiz = 0;
    do {
        csum += tmp;
        csiz++;
        tmp *= tmp;
        tmp %= M;
    } while (tmp != now);

    ans += (N / csiz) * csum;
    N %= csiz;

    for (int i = 0; i < N; ++i) {
        ans += now;
        now *= now;
        now %= M;
    }

    cout << ans << endl;

    return 0;
}
