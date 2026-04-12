#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= int(a); --i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, int(n) + 1)
#define rrep(i, n) RFOR(i, 0, n)
#define rrep1(i, n) RFOR(i, 1, int(n) + 1)
#define all(c) begin(c), end(c)
const int MOD = 1000000007;

template <typename T>
void __dump__(std::ostream &os, const T &first) {
    os << first;
}
template <typename First, typename... Rest>
void __dump__(std::ostream &os, const First &first, const Rest &... rest) {
    os << first << ", ";
    __dump__(os, rest...);
}
#define dump(...)                                         \
    do {                                                  \
        std::ostringstream os;                            \
        os << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; \
        __dump__(os, __VA_ARGS__);                        \
        std::cerr << os.str() << std::endl;               \
    } while (0)


int n;

signed main() {
    while (cin >> n) {
        deque<int> d;
        rep(i, n) {
            int a;
            cin >> a;
            if (i&1) d.push_back(a);
            else d.push_front(a);
        }
        if (n&1) {
            rep(i, n) cout << d[i] << ' ';
        } else {
            rrep(i, n) cout << d[i] << ' ';
        }
        cout << endl;
    }
}
