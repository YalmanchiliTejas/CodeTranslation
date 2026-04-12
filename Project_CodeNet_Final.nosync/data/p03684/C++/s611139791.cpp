#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 0; i < n; ++i)
#define rep3(i, a, b) for (ll i = a; i < b; ++i)
#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)
#define erep(n) for (ll i = 0; i <= n; ++i)
#define erep2(i, n) for (ll i = 0; i <= n; ++i)
#define erep3(i, a, b) for (ll i = a; i <= b; ++i)
#define erep4(i, a, b, c) for (ll i = a; i <= b; i += c)
#define rrep(i, a, b) for (ll i = a; i > b; --i)
#define rrep2(i, a, b, c) for (ll i = a; i > b; i -= c)
#define errep(i, a, b) for (ll i = a; i >= b; --i)
#define errep2(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define print(a) cout << a << endl;
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define cin(x) cin >> x;
const ll MOD = 1000000007;
const double PI = 3.14159265358979323846264338327950;
inline int newline() { putchar('\n'); return 0; }

int main() {
    using P = pair<ll, ll>;

    ll n;
    cin(n);

    vector<P> x(n), y(n);
    /// - Note:
    ///
    /// first:  x or y 座標
    /// second: index
    rep2(i, n) {
        ll tempX, tempY;
        cin(tempX); cin(tempY);

        x[i] = make_pair(tempX, i);
        y[i] = make_pair(tempY, i);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    vector<vector<P>> relations(n, vector<P>());
    rep2(i, n - 1) {
        P from = x[i];
        P to = x[i + 1];

        ll cost = abs(from.first - to.first);
        relations[from.second].push_back(make_pair(cost, to.second));
        relations[to.second].push_back(make_pair(cost, from.second));
    }
    rep2(i, n - 1) {
        P from = y[i];
        P to = y[i + 1];

        ll cost = abs(from.first - to.first);
        relations[from.second].push_back(make_pair(cost, to.second));
        relations[to.second].push_back(make_pair(cost, from.second));
    }

    // rep2(i, n) {
    //     for (auto i: relations[i]) {
    //         printf("%lld -> %lld: %lld\n", i, i.second, i.first);
    //     }
    // }

    vector<bool> used(n, false);
    ll result = 0;
    priority_queue<P, vector<P>, greater<>> que;
    que.push(make_pair(0, 0));

    while (!que.empty()) {
        P top = que.top();
        que.pop();

        if (used[top.second]) continue;
        used[top.second] = true;
        result += top.first;

        for (auto i: relations[top.second]) {
            if (!used[i.second]) {
                que.push(i);
            }
        }
    }

    print(result);
    return 0;
}