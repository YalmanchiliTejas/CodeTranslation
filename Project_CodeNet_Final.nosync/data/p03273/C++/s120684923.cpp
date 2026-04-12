#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    vector<vector<char>> b(H, vector<char>(W, 'a'));
    rep(i, H) rep(j, W) cin >> a[i][j];


    rep(i, H) {
        if(a[i][0] == '#') continue;
        char prev = a[i][0];
        bool isSame = true;
        for(int j=1; j<W; j++) {
            if(a[i][j] != prev) {
                isSame = false;
                break;
            }
        }
        if(isSame) rep(j, W) b[i][j] = 'n';
    }

    rep(i, W) {
        if(a[0][i] == '#') continue;
        char prev = a[0][i];
        bool isSame = true;
        for(int j=1; j<H; j++) {
            if(a[j][i] != prev) {
                isSame = false;
                break;
            }
        }
        if(isSame) rep(j, H) b[j][i] = 'n';
    }

   
    rep(i, H) {
        bool ent = false;
        rep(j, W) {
            if(b[i][j] == 'n') continue;
            ent = true;
            cout << a[i][j];
        }
        if(ent) cout << endl;
    }

    return 0;
}