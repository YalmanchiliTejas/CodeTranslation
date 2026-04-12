#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = std::vector<int>;
using Vl = std::vector<ll>;
using Pii = std::pair<int, int>;
using Pll = std::pair<ll, ll>;

constexpr int I_INF = std::numeric_limits<int>::max();
constexpr ll L_INF = std::numeric_limits<ll>::max();

template <typename T1, typename T2>
inline bool chmin(T1& a, const T2& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T1, typename T2>
inline bool chmax(T1& a, const T2& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

class Prints {
private:
    class __Prints {
    public:
        __Prints(const char* sep, const char* term) : sep(sep), term(term) {}
        template <class... Args>
        void operator()(const Args&... args) const { print(args...); }
        template <typename T>
        void pvec(const T& vec, size_t sz) const {
            for (size_t i = 0; i < sz; i++)
                std::cout << vec[i] << (i == sz - 1 ? term : sep);
        }
        template <typename T>
        void pmat(const T& mat, size_t h, size_t w) {
            for (size_t i = 0; i < h; i++)
                for (size_t j = 0; j < w; j++)
                    std::cout << mat[i][j] << (j == w - 1 ? term : sep);
        }

    private:
        const char *sep, *term;
        void print() const { std::cout << term; }
        void print_rest() const { std::cout << term; }
        template <class T, class... Tail>
        void print(const T& head, const Tail&... tail) const { std::cout << head, print_rest(tail...); }
        template <class T, class... Tail>
        void print_rest(const T& head, const Tail&... tail) const { std::cout << sep << head, print_rest(tail...); }
    };

public:
    Prints() {}
    __Prints operator()(const char* sep = " ", const char* term = "\n") const { return __Prints(sep, term); }
};

Prints prints;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void solve() {
    ll N, X, M;
    cin >> N >> X >> M;
    Vi vs(M);

    Vl chain;
    bool flg = false;
    ll cur = X % M;
    ++vs[X % M];
    while (true) {
        ll nxt = cur * cur % M;
        if (!flg) {
            if (vs[nxt] == 1) {
                flg = true;
                chain.emplace_back(nxt);
            }
        }
        else {
            if (vs[nxt] == 2) {
                break;
            }
            else {
                chain.emplace_back(nxt);
            }
        }
        ++vs[nxt];
        cur = nxt;
    }

    ll ans = 0;
    ll cnt = 0;
    cur = X % M;
    while (vs[cur] == 1 && cnt < N) {
        ans += cur;
        ++cnt;
        cur = cur * cur % M;
    }

    if (cnt < N) {
        ll sz = (ll)chain.size();
        Vl cum(sz + 1);
        for (ll i = 0; i < sz; i++) {
            cum[i + 1] = cum[i] + chain[i];
        }
        ll c = N - cnt;
        ll loop, r;
        loop = c / sz;
        r = c % sz;
        ans += cum[sz] * loop;
        ans += cum[r];
    }

    prints()(ans);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main() {
#ifdef FASTIO
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    std::ifstream ifs("./in_out/input.txt");
    std::cin.rdbuf(ifs.rdbuf());
#endif
#ifdef FILEOUTPUT
    std::ofstream ofs("./in_out/output.txt");
    std::cout.rdbuf(ofs.rdbuf());
#endif
    std::cout << std::setprecision(18) << std::fixed;
    solve();
    std::cout << std::flush;
    return 0;
}