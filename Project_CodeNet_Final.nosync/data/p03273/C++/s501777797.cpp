#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;


int main() {

    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];
    vector<bool> row(h, false);
    vector<bool> col(h, false);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        if (row[i]) {
            for (int j = 0; j < w; ++j){
                if (col[j]) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}