/*
    - Note:
    https://atcoder.jp/contests/arc076/tasks/arc076_b
*/

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

    /*
        - Note:
        first -> x or y
        second -> index
    */
    vector<P> x(n), y(n);
    rep2(i, n) {
        ll _x, _y;
        cin(_x); cin(_y);

        x[i] = { _x, i };
        y[i] = { _y, i };
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    vector<vector<P>> relations(n);
    rep2(i, n - 1) {
        P from = x[i], to = x[i + 1];

        ll cost = abs(from.first - to.first);
        relations[from.second].push_back({ cost, to.second });
        relations[to.second].push_back({ cost, from.second });
    }
    rep2(i, n - 1) {
        P from = y[i], to = y[i + 1];

        ll cost = abs(from.first - to.first);
        relations[from.second].push_back({ cost, to.second });
        relations[to.second].push_back({ cost, from.second });
    }

    vector<bool> used(n, false);
    ll result = 0;
    priority_queue<P, vector<P>, greater<>> que;

    que.push({ 0, 0 });

    while (!que.empty()) {
        P top = que.top();
        que.pop();

        if (used[top.second]) continue;

        used[top.second] = true;
        result += top.first;

        for (auto i: relations[top.second]) {
            if (!used[i.second]) que.push(i);
        }
    }

    print(result);
    return 0;
}