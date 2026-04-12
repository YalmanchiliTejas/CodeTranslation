#ifdef _DEBUG
#include ".vscode/debug_print.hpp"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
constexpr int INF32       = 1050000000;
constexpr long long INF64 = 4000000000000000000;
constexpr int MOD7        = 1000000007;
constexpr int MOD53       = 998244353;
constexpr long double PI  = 3.14159265358979323846;
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

void vprint() { std::cout << '\n'; }
template <class H, class... T> void vprint(H &&head, T &&... args) {
    std::cout << head;
    sizeof...(args) == 0 ? std::cout << "" : std::cout << '\n';
    vprint(std::forward<T>(args)...);
}
template <class T> void vprint(std::vector<T> &v) {
    for (auto &&i : v) {
        std::cout << i << '\n';
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    string s;
    scan(s);
    if (s == "AAA" || s == "BBB") {
        print("No");
    } else {
        print("Yes");
    }

    return 0;
}