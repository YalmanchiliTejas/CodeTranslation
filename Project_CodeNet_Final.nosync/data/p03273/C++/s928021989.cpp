#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w; cin >> h >> w;
    vector<vector<char>> v(h, vector<char>(w));
    vector<int> hc(h, 1);
    vector<int> wc(w, 1);
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> v[i][j];
        }
    }

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (v[i][j] == '#') {
                hc[i] = 0;
            }
        }
    }
    
    for (int i=0; i<w; i++) {
        for (int j=0; j<h; j++) {
            if (v[j][i] == '#') {
                wc[i] = 0;
            }
        }
    }

    for (int i=0; i<h; i++) {
        if (hc[i] == 0) {
            for (int j=0; j<w; j++) {
                if (wc[j] == 0) {
                    cout << v[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}

