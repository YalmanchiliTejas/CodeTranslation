#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
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
    int n;
    cin >> n;
    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ret = 0;
    while (true) {
        ll k = 0;
        vl b(n);
        for (int i = 0; i < n; ++i) {
            b[i] = a[i] / n;
            k += b[i];
        }
        ret += k;
        for (int i = 0; i < n; ++i) {
            a[i] = a[i] % n + k - b[i];
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= n) {
                ok = false;
                break;
            }
        }
        if (ok)
            break;
    }
    cout << ret << "\n";
    return 0;
}