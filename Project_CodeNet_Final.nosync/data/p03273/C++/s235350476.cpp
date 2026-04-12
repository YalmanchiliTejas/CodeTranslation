#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, s, e) for (int i = (int)(s); i < (int)(e); i++)
#define _rep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define _REP(i, e, s) for (int i = (int)(e - 1); i >= (int)(s); i--)

#define yes cout << "yes" << endl;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;

#define no cout << "no" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;

#define AC cout << "AC" << endl;
#define WA cout << "WA" << endl;

#define out(s) cout << s << endl;

#define ll long long
#define ull unsigned long long
#define vi vector<int>

const double PI = 3.14159265358979323846;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for (int i = 0; i < H; i++) {
        cin >> a[i];
    }

    vector<bool> row(H, false);
    vector<bool> col(W, false);
    rep(i, H) {
        rep(j, W) {
            if (a[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    rep(i, H) {
        if (row[i]) {
            rep(j, W) {
                if (col[j]) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
}