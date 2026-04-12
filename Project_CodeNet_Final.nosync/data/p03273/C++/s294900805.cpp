#include <bits/stdc++.h> 
using namespace std;

int main() {
    int h, w; cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> a[i][j];
        }
    }

    vector<bool> b(h, false);
    vector<bool> c(w, false);
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(a[i][j] == '#') {
                b[i] = true;
                c[j] = true;
            }
        }
    }
    for(int i=0; i<h; i++) {
        if(b[i]) {
            for(int j=0; j<w; j++) {
                if(c[j]) cout << a[i][j];
            }
            cout << endl;
        }
    }
}