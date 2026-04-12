#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 1e9;
// const int MOD = 1e9 + 7;

int main() {
    int H, W;
    cin >> H >> W;
    auto a = make_vec<char>(H, W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<char>> b;
    for (int i = 0; i < H; i++) {
        bool flag = false;
        for (int j = 0; j < W; j++) {
            if (a[i][j] == '#') {
                flag = true;
                break;
            }
        }
        if (flag) {
            b.push_back(a[i]);
        }
    }
    H = (int)b.size();
    vector<int> p;
    for (int j = 0; j < W; j++) {
        bool flag = false;
        for (int i = 0; i < H; i++) {
            if (b[i][j] == '#') {
                flag = true;
                break;
            }
        }
        if (flag) {
            p.push_back(j);
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < (int)p.size(); j++) {
            cout << b[i][p[j]];
        }
        cout << "\n";
    }
}
