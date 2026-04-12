#include <bits/stdc++.h>
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define REP(i, n) for (long long i = 0; i < n; i++)
#define RREP(i, n) for (long long i = n - 1; 0 <= i; i--)
#define FOR(i, start, end) for (long long i = start; i < end; i++)
#define RFOR(i, start, end) for (long long i = start - 1; 0 <= i; i--)
#define ALL(a) a.begin(), a.end()
#define MOD(a) a %= 1'000'000'007
using ll = long long;
using namespace std;
const int INF32       = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7        = 1'000'000'007;
const int MOD9        = 1'000'000'009;
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    for (auto &&i : a) {
        for (auto &&j : i) {
            cin >> j;
        }
    }

    auto yes = []() {
        print("Possible");
        exit(0);
    };
    auto no = []() {
        print("Impossible");
        exit(0);
    };
    int mx = 0;
    REP(y, H) {
        REP(x, W) {
            if (a[y][x] == '#' && mx <= x) {
                mx = x;
            } else if (a[y][x] == '#') {
                no();
            }
        }
    }
    yes();

    return 0;
}