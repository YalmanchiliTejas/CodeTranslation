#include <bits/stdc++.h>

#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)


using namespace std;
using ll = long long;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> tb(h, vector<bool>(w));

    for (auto &&a:tb) {
        for (auto &&b:a) {
            char c;
            cin >> c;
            b = (c == '.');
        }
    }

    vector<unsigned> r(h, false);
    vector<unsigned> c(w, false);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!tb[i][j]) {
                r[i] = true;
                c[j] = true;
            }
        }
    }

    unsigned nr = false;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (r[i] & c[j]) {
                nr |= r[i] & c[j];
                cout << (tb[i][j] ? '.' : '#');
            }
        }
        if (nr) {
            nr = 0;
            cout << endl;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);

    solve();
    return 0;
}
