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
    vl s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    ll ret = 0;
    for (int i = 1; i <= n; ++i) {
        bitset<100000> used;
        used[0] = used[n - 1] = 1;
        ll temp               = 0;
        for (int j = 1; j < n; ++j) {
            int left  = j * i;
            int right = n - 1 - j * i;
            if (left > n - 1 - i || right < i)
                break;
            // if (left >= right)
            //     break;
            if (left == right)
                break;
            if (used[left] == 1 || used[right] == 1)
                break;
            used[left] = used[right] = 1;
            temp += s[left] + s[right];
            chmax(ret, temp);
        }
    }
    cout << ret << "\n";
    return 0;
}