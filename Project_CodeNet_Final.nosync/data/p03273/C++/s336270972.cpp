#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < ll(n); i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char> (w));
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < h;) {
        bool z = true;
        rep(j, w) {
            if(a[i][j] == '#') {z = false; break;}
        }
        if(z) {
            a.erase(a.begin() + i);
            h--;
        } else {
            i++;
        }
    }

    for(int j = 0; j < w;) {
        bool z = true;
        rep(i, h) {
            if(a[i][j] == '#') {z = false; break;}
        }
        if(z) {
            for(auto it = a.begin(); it != a.end(); it++) {
                it->erase(it->begin() + j);
            }
            w--;
        } else {
            j++;
        }
    }

    rep(i, h) {
        rep(j, w) {
            cout << a[i][j];
        }
        cout << endl;
    }
}
