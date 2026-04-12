#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M (ll)1000000007
#define MM (ll)1e8
#define INF (ll)1e18
#define arep(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
// using ll = long long;

int main() {
    ll h;
    ll w;
    cin >> h >> w;

    char a[h][w];
    bool b[h][w];

    rep(i, h) {
        string text;
        cin >> text;
        rep(j, w) {
            a[i][j] = text.at(j);
            b[i][j] = true;
        }
    }

    ll cnt = 0;

    rep(i, h) {
        bool toRemove = true;
        rep(j, w) {
            if (a[i][j] == '#') {
                toRemove = false;
                break;
            }
        }

        if (toRemove) {
            rep(j, w) { b[i][j] = false; }
        }
    }

    rep(j, w) {
        bool toRemove = true;
        rep(i, h) {
            if (a[i][j] == '#') {
                toRemove = false;
                break;
            }
        }

        if (toRemove) {
            rep(i, h) { b[i][j] = false; }
        }
    }

    rep(i, h) {
        bool rowRemoved = true;
        rep(j, w) {
            if (b[i][j] == true) {
                cout << a[i][j];
                rowRemoved = false;
            }
        }

        if (rowRemoved == false) cout << endl;
    }
}