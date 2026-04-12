#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool Check(const int i, const int j, const int h, const int w,
           const vector<string> &a) {

    bool is_delete = true;
    for (int k = 0; k < w; ++k)
        if (a[i][0] != a[i][k]) is_delete = false;

    if (is_delete) return false;
    is_delete = true;
    for (int k = 0; k < h; ++k)
        if (a[0][j] != a[k][j]) is_delete = false;

    return !is_delete;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int h, w;

    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; ++i) cin >> a[i];

    for (int i = 0; i < h; ++i) {
        bool is_delete = true;
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == '#' || Check(i, j, h, w, a)) {
                cout << a[i][j];
                is_delete = false;
            }
        }
        if (!is_delete) cout << '\n';
    }

    return 0;
}
