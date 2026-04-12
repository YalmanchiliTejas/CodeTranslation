#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 100010;

int main() {
    int h, w; cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    vector<bool> H(h, false);
    vector<bool> W(w, false);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                H[i] = true;
                W[j] = true;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (H[i] && W[j]) cout << a[i][j];
        }
        if (H[i]) cout << endl;
    }
}