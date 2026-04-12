#include <bits/stdc++.h>
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define RREP(i, n) for (int i = n - 1; 0 <= i; i--)
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = start - 1; 0 <= i; i--)
#define ALL(a) a.begin(), a.end()
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

    int N;
    cin >> N;
    vector<ll> v(N);
    for (auto &&i : v) {
        cin >> i;
    }
    SORT(v);
    ll ans = 0;
    if (N % 2 == 0) {
        ans += -v[N / 2 - 1] + v[N / 2];
        REP(i, N) {
            if (i == N / 2 - 1 || i == N / 2)
                continue;
            else if (i < N / 2)
                ans -= 2 * v[i];
            else
                ans += 2 * v[i];
        }
    } else {
        ll mx = +v[N / 2] + v[N / 2 + 1];
        ll mn = -v[N / 2 - 1] - v[N / 2];
        REP(i, N) {
            bool mxf = true, mnf = true;
            if (i == N / 2 || i == N / 2 + 1)
                mxf = false;
            if (i == N / 2 - 1 || i == N / 2)
                mnf = false;
            if (i <= N / 2) {
                if (mxf)
                    mx -= 2 * v[i];
                if (mnf)
                    mn -= 2 * v[i];
            } else {
                if (mxf)
                    mx += 2 * v[i];
                if (mnf)
                    mn += 2 * v[i];
            }
        }
        ans = max(mx, mn);
    }

    print(ans);
    return 0;
}