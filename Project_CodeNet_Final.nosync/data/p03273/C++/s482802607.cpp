//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

//----------------------- Print Function ----------------------//

inline void print() {
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest) {
    cout << first << ' ';
    print(rest...);
}

template <typename T>
void print(const vector<T> &v) {
    for (auto e : v) cout << e << ' ';
    cout << endl;
}

//------------------------- Libraries -------------------------//

//--------------------------- Solve ---------------------------//

void solve() {
    int H, W; cin >> H >> W;
    vector<string> a(H);
    for (int i = 0; i < H; i++) cin >> a[i];

    vector<int> h, w;
    for (int i = 0; i < H; i++) {
        bool flag = true;
        for (int j = 0; j < W; j++) {
            if (a[i][j] == '#') flag = false;
        }
        if (!flag) h.push_back(i);
    }

    for (int j = 0; j < W; j++) {
        bool flag = true;
        for (int i = 0; i < H; i++) {
            if (a[i][j] == '#') flag = false;
        }
        if (!flag) w.push_back(j);
    }

    for (int i : h) {
        for (int j : w) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}