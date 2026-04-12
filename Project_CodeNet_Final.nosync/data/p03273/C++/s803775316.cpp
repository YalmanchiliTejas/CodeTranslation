#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    int H, W; cin >> H >> W;
    vector<vc> A(H, vc(W)) ;
    rep(i, H) rep(j, W) cin >> A[i][j];

    vi x;
    rep(i, H) {
        int cnt = 0;
        rep(j, W) {
            if (A[i][j] == '.') cnt++;
        }
        if (cnt != W) {
            x.push_back(i);
        }
    }

    vi y;
    rep(j, W) {
        int cnt = 0;
        rep(i, H) {
            if (A[i][j] == '.') cnt++;
        }
        if (cnt != H) {
            y.push_back(j);
        }
    }

    rep(i, x.size()) {
        rep(j, y.size()) {
            cout << A[x[i]][y[j]];
        }
        cout << endl;
    }
}