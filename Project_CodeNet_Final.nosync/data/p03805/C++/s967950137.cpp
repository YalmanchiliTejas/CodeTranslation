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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    scan(N, M);
    vector<vector<int>> g(N, vector<int>(N, false));
    rep(i, M) {
        int a, b;
        scan(a, b);
        g[a - 1][b - 1] = true;
        g[b - 1][a - 1] = true;
    }
    vector<int> v(N);
    iota(all(v), 0);

    int ans = 0;
    debug(v);
    do {
        bool ok = true;
        if (v[0] != 0)
            continue;
        rep(i, N - 1) {
            int now = v[i];
            int nxt = v[i + 1];
            if (!g[now][nxt])
                ok = false;
        }
        if (ok)
            ans++;
    } while (next_permutation(all(v)));
    print(ans);
    return 0;
}