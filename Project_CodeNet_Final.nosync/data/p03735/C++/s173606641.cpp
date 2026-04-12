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
    vector<pll> xy;
    ll xmax = 0, ymax = 0, xmin = 1e10, ymin = 1e10;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        xy.emplace_back(x, y);
        chmax(xmax, x);
        chmax(ymax, y);
        chmin(xmin, x);
        chmin(ymin, y);
    }
    sort(xy.begin(), xy.end());
    ll ret  = INF;
    ll smax = 0, smin = 1e10;
    for (int i = 0; i < n; ++i) {
        chmax(smax, min(xy[i].first, xy[i].second));
        chmin(smin, max(xy[i].first, xy[i].second));
    }
    ll maxi = max(xmax, ymax);
    ll mini = min(xmin, ymin);
    chmin(ret, (smax - mini) * (maxi - smin));

    smax = 0, smin = 1e10;
    chmin(ret, (maxi - mini) * (xy[n - 1].first - xy[0].first));
    for (int i = 0; i < n; ++i) {
        chmax(smax, xy[i].second);
        chmin(smin, xy[i].second);
        chmin(ret, (maxi - mini) * (max(smax, xy[n - 1].first) - min(smin, xy[i + 1].first)));
    }
    cout << ret << "\n";
    return 0;
}