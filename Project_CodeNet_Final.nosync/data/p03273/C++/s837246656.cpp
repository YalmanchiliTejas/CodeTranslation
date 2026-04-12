#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int H, W;
    cin >> H >> W;

    vector<string> a(H);
    rep(i, H) cin >> a[i];

    vector<bool> row(H);
    rep(i, H) {
        bool res = true;
        rep(j, W) {
            if (a[i][j] != '.') {
                res = false;
                break;
            }
        }
        row[i] = res;
    }

    vector<bool> col(W);
    rep(i, W) {
        bool res = true;
        rep(j, H) {
            if (a[j][i] != '.') {
                res = false;
                break;
            }
        }
        col[i] = res;
    }

    rep(i, H) {
        rep(j, W) {
            if (!row[i] && !col[j]) {
                cout << a[i][j];
            }
        }
        if (!row[i]) cout << endl;
    }
}