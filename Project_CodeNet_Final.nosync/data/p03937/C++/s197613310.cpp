#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    int i = 0, j = 0;
    while (i != H - 1 || j != W - 1) {
        S[i][j] = '.';
        if (i == H - 1) {
            if (S[i][j + 1] == '.') {
                cout << "Impossible\n";
                return 0;
            }
            j++;
            continue;
        } else if (j == W - 1) {
            if (S[i + 1][j] == '.') {
                cout << "Impossible\n";
                return 0;
            }
            i++;
            continue;
        } else {
            if (S[i][j + 1] == '.') {
                if (S[i + 1][j] == '.') {
                    cout << "Impossible\n";
                    return 0;
                }
                i++;
                continue;
            } else {
                if (S[i + 1][j] == '#') {
                    cout << "Impossible\n";
                    return 0;
                }
                j++;
                continue;
            }
        }
    }
    S[H - 1][W - 1] = '.';
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') {
                    cout << "Impossible\n";
                    return 0;
            }
        }
    }
    cout << "Possible\n";
}