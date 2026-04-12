// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vii = vector<int>;
using pii = pair<int, int>;
template <typename T = vii>
using vec = vector<T>;

const ll INF = 1e18, MOD = 1e9 + 7;

const int MAX = 1e6;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("in.in", "r", stdin);

    int n;
    cin >> n;
    vii v(n);
    for (auto &e : v) {
        cin >> e;
    }
    multiset<int> s;
    int res = 0;
    for (auto e : v) {
        auto it = s.lower_bound(e);
        if (it == s.begin() or s.empty()) {
            res++;
        }
        else {
            s.erase(--it);
        }
        s.insert(e);
    }
    cout << res << '\n';
}