#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W, '.'));
    rep(i, H) {
        rep(j, W) {
            cin >> a.at(i).at(j);
        }
    }

    vector<bool> row(H, false);
    vector<bool> col(W, false);

    rep(i, H) {
        rep(j, W) {
            if (a.at(i).at(j) == '#') {
                row.at(i) = true;
                col.at(j) = true;
            }
        }
    }

    rep(i, H) {
        rep(j, W) {
            if(row.at(i) == true && col.at(j) == true) {
                cout << a.at(i).at(j);
            }
        }
        if(row.at(i) == true) cout << endl;
    }

    return 0;
}
