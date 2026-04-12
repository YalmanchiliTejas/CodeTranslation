#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int h, w; cin >> h >> w;
    vector<string> a(h);
    for(int i = 0; i < h; ++i) {
        cin >> a[i];
    }
    vector<bool> row(h), col(w);
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(a[i][j] == '#') {
                row[i] = col[j] = true;
            }
        }
    }

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(row[i] && col[j]) cout << a[i][j];
        }
        cout << endl;
    }
}
