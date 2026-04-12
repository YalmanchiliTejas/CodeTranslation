#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    ll H, W; cin >> H >> W;
    vector<string> S(H, "");
    rep(i,H) {
        cin >> S[i];
    }
    vector<string> S2;
    rep(i, H) {
        bool allw = true;
        rep(j, W) {
            if (S[i][j] == '#') {
                allw = false;
                break;
            }
        }
        if (allw == false) {
            S2.push_back(S[i]);
        }
    }
    map<ll,ll> eraser;
    rep(i, W) {
        bool allw = true;
        rep(j, S2.size()) {
            if (S2[j][i] == '#') {
                allw = false;
                break;
            }
        }
        if (allw) {
            eraser[i] = 1;
        }
    }
    rep(i,S2.size()) {
        rep(j,W) {
            if (eraser[j]) continue;
            cout << S2[i][j];
        }
        cout << endl;
    }
}
