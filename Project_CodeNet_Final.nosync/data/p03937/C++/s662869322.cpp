#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const int INF = 1 << 28;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
    }
    int x = 0;
    int y = 0;
    a[0][0] = '.';
    while (!(y == h - 1 && x == w - 1)) {
        if (y < h - 1 && a[y + 1][x] == '#') {
            a[y + 1][x] = '.';
            y++;
        } else if (x < w - 1 && a[y][x + 1] == '#') {
            a[y][x + 1] = '.';
            x++;
        } else {
            break;
        }
    }
    bool ok = true;
    for (int i = 0; i < h; ++i) {
        if (a[i] != string(w, '.')) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "Possible"
             << "\n";
    } else {
        cout << "Impossible"
             << "\n";
    }
    return 0;
}