#include <bits/stdc++.h>
using ll = long long;
// #define int ll
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= int(a); --i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, int(n) + 1)
#define rrep(i, n) RFOR(i, 0, n)
#define rrep1(i, n) RFOR(i, 1, int(n) + 1)
#define all(c) begin(c), end(c)
const int MOD = 1000000007;

template <typename T>
void __print__(std::ostream &os, const char *, const char *tail, const T &fst) {
    os << fst << tail;
}
template <typename Fst, typename... Rst>
void __print__(std::ostream &os, const char *del, const char *tail, const Fst &fst,
               const Rst &... rst) {
    os << fst << del;
    __print__(os, del, tail, rst...);
}

#ifdef LOCAL
#define dump(...)                                         \
    do {                                                  \
        std::ostringstream os;                            \
        os << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; \
        __print__(os, ", ", "\n", __VA_ARGS__);           \
        std::cerr << os.str();                            \
    } while (0)
#else
#define dump(...)
#endif

template <typename Fst, typename... Rst>
void println(const Fst &fst, const Rst &... rst) {
    __print__(std::cout, "\n", "\n", fst, rst...);
}
template <typename Fst, typename... Rst>
void print(const Fst &fst, const Rst &... rst) {
    __print__(std::cout, " ", "\n", fst, rst...);
}

template <typename iter>
void println_(iter bgn, iter end) {
    while (bgn != end) println(*bgn++);
}

template <typename iter>
void print_(iter bgn, iter end) {
    while (bgn != end) {
        std::cout << *bgn++;
        std::cout << (bgn == end ? "\n" : " ");
    }
}

int _ = (std::cout.precision(10), std::cout.setf(std::ios::fixed), std::cin.tie(0),
         std::ios::sync_with_stdio(0), 0);

template <typename T>
std::vector<T> ndarray(int n, T v) {
    return std::vector<T>(n, v);
}
template <typename... Args>
auto ndarray(int n, Args... args) {
    auto val = ndarray(args...);
    return std::vector<decltype(val)>(n, move(val));
}

template <typename T>
bool umax(T &a, const T &b) {
    return a < b ? a = b, true : false;
}

template <typename T>
bool umin(T &a, const T &b) {
    return a > b ? a = b, true : false;
}

using namespace std;

string a, b;

vector<int> sub(string S, string s) {
    vector<int> idx;
    int i = 0;
    for (char c : s) {
        while (i < (int)S.size() && S[i] != c) ++i;
        if (i == (int)S.size()) return {};
        idx.push_back(i);
        ++i;
    }
    return idx;
}

bool solve() {
    vector<int> org = sub(a, b);
    if (org.size() == 0) return false;
    reverse(all(a));
    reverse(all(b));
    vector<int> rev = sub(a, b);
    // print_(all(org));
    reverse(all(rev));
    // print_(all(rev));
    rep(i, rev.size()) {
        dump(org[i], rev[i], a.size() - 1);
        if (org[i] + rev[i] != (int)a.size() - 1) return false;
    }
    return true;
}

int main() {
    while (cin >> a >> b) {
        print(solve() ? "yes" : "no");
    }
}