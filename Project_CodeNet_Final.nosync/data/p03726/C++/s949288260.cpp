#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

int main() {
    ll n;
    cin >> n;
    vvi edges(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<bool> used(n, false);
    function<void(int, int)> dfs = [&](int c, int p) {
        for (auto &v : edges[c]) {
            if (v == p)
                continue;
            dfs(v, c);
        }
        if (!used[c] && p != -1 && !used[p]) {
            used[c] = used[p] = true;
        }
    };
    dfs(0, -1);
    bool match = true;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            match = false;
            break;
        }
    }
    if (match) {
        cout << "Second"
             << "\n";
    } else {
        cout << "First"
             << "\n";
    }
    return 0;
}