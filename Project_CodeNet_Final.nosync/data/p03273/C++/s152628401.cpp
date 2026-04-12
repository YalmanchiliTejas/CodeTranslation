#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

int main() {
    int h, w; cin >> h >> w;
    vector<string> a(h);
    for (int i=0; i<h; ++i) cin >> a[i];
    string checker1 = "";
    for (int i=0; i<w; ++i) checker1 += '.';
    vector<bool> wh(h), ww(w);
    for (int i=0; i<h; ++i) {
        if (a[i] == checker1) wh[i] = true;
    }
    string checker2 = "";
    for (int i=0; i<h; ++i) checker2 += '.';
    for (int i=0; i<w; ++i) {
        string t = "";
        for (int j=0; j<h; ++j) {
            t += a[j][i];
        }
        if (t == checker2) ww[i] = true;
    }
    for (int i=0; i<h; ++i) {
        if (wh[i]) continue;
        for (int j=0; j<w; ++j) {
            if (ww[j]) continue;
            cout << a[i][j];
        }
        cout << endl;
    }
}