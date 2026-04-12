#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }
    pii now = {0, 0};
    vector<vector<int>> flag(H, vector<int>(W, 0));
    flag[0][0] = 1;
    while(now != make_pair(H - 1, W - 1)) {
        int fl1 = 0, fl2 = 0;
        if (now.first + 1 < H && A[now.first + 1][now.second] == '#') {
            fl1 = 1;
        }
        if (now.second + 1 < W && A[now.first][now.second + 1] == '#') {
            fl2 = 1;
        }
        if (fl1 && fl2) {
            cout << "Impossible" << endl;
            return;
        }
        if (!fl1 && !fl2) {
            cout << "Impossible" << endl;
            return;
        }
        if (fl1) {
            now.first += 1;
        } else {
            now.second += 1;
        }
        flag[now.first][now.second] = 1;
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#' && !flag[i][j]) {
                cout << "Impossible" << endl;
                return;
            }
        }
    }
    cout << "Possible" << endl;

}

int main() {
    #ifdef LOCAL_ENV
    cin.exceptions(ios::failbit);
    #endif
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    
    solve();
}