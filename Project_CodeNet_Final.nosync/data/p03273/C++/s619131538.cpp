#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr ll INF = ll(1e+18) + 1;

ll dist(ll a, ll b, ll c, ll d) {
    return abs(a-c) + abs(b-d);
}

int main() {
    int H, W;
    vector<string> a;
    vector<bool> colwhite;
    vector<bool> rowwhite;

    cin >> H >> W;
    rep(i, W) {
        colwhite.push_back(true);
    }
    rep (i, H) {
        string buf;
        cin >> buf;
        a.push_back(buf);

        rowwhite.push_back(true);
        rep (j, W) {
            if (buf[j] == '#') {
                colwhite[j] = false;
                rowwhite[rowwhite.size()-1] = false;
            }
        }
    }

    rep (i, H) {
        if (rowwhite[i] == true) {continue;}
        rep(j, W) {
            if (colwhite[j] == false) {
                cout << a[i][j];
            }
        }
        cout << endl;
    }

}
