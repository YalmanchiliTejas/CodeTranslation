#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

class Main {
    ll N, X, M;
    void input() { cin >> N >> X >> M; }
    void output() {
        ll res = X;
        ll i = 1;
        set<ll> st;
        ll r = X % M;
        vector<ll> v;
        for (; i < N; ++i) {
            r = r * r % M;
            if (st.count(r)) break;
            st.emplace(r);
            v.emplace_back(r);
        }
        if (i == N) {
            for (auto &x : v) { res += x; }
            cout << res << endl;
            return;
        }
        ll j = 0;
        for (; j < v.size(); ++j) {
            if (v[j] == r) break;
            res += v[j];
        }
        vector<ll> csum = {0};
        for (ll k = j; k < v.size(); ++k) {
            csum.emplace_back(csum.back() + v[k]);
        }
        res += (N - 1 - j) / (v.size() - j) * csum.back();
        res += csum[(N - 1 - j) % (v.size() - j)];
        cout << res << endl;
    }

public:
    Main() {
        input();
        output();
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Main();

    return 0;
}
