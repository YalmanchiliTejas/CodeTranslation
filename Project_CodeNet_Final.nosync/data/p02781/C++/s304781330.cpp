#include <bits/stdc++.h>
#ifdef _DEBUG
#include "../../../debug_print.hpp"
#else
#define debug(...)
#endif
#define sort_(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; 0 <= i; i--)
#define for_(i, start, end) for (int i = start; i < end; i++)
#define rfor(i, start, end) for (int i = start - 1; 0 <= i; i--)
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using namespace std;
constexpr int INF32       = 1'050'000'000;
constexpr long long INF64 = 4'000'000'000'000'000'000;
constexpr int MOD7        = 1'000'000'007;
constexpr int MOD53       = 998'244'353;
constexpr double PI       = 3.14159265358979323846;
template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
void print() { std::cout << '\n'; }
template <class H, class... T> void print(H &&head, T &&... args) {
    std::cout << head;
    sizeof...(args) == 0 ? std::cout << "" : std::cout << ' ';
    print(std::forward<T>(args)...);
}
template <class T> void print(std::vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        i == v.size() - 1 ? std::cout << '\n' : std::cout << ' ';
    }
}
template <class T> void print(std::vector<std::vector<T>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            std::cout << v[i][j];
            j == v[i].size() - 1 ? std::cout << '\n' : std::cout << ' ';
        }
    }
}
void scan() {}
template <class H, class... T> void scan(H &&head, T &&... args) {
    std::cin >> head;
    scan(std::forward<T>(args)...);
}
template <class T> void scan(std::vector<T> &v) {
    for (auto &&i : v) {
        scan(i);
    }
}

template <class T> T nCr(T n, T r) {
    if (r > n)
        return 0;
    if (r * 2 > n)
        r = n - r;
    if (r == 0)
        return 1;
    T ans = n;
    for (T i = 2; i <= r; i++) {
        ans *= (T)(n - i + 1);
        ans /= (T)i;
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    int K;
    scan(s, K);
    int N = s.size();

    vector<vector<vector<int>>> dp(N + 1,
                                   vector<vector<int>>(4, vector<int>(2)));

    dp[0][0][0] = 1;
    rep(i, N) {
        rep(j, 4) {
            rep(k, 2) {
                int nd = s[i] - '0';
                rep(d, 10) {
                    int ni = i + 1;
                    int nj = j;
                    int nk = k;
                    if (d != 0)
                        nj++;
                    if (K < nj)
                        continue;
                    if (k == 0) {
                        if (nd < d)
                            continue;
                        if (d < nd)
                            nk = 1;
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }
    int ans = dp[N][K][0] + dp[N][K][1];
    print(ans);

    return 0;
}