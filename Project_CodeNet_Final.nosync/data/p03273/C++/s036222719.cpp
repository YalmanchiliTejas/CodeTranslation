#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int h, w;  cin >> h >> w;
    vector<int> row(h, 1);
    vector<int> cols(w, 1);
    char a[h][w];

    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                row[i] = 0;
                cols[j] = 0;
            }
        }
    }

    for (int i=0; i<h; ++i) {
        if (row[i]) continue;
        for (int j=0; j<w; ++j) {
            if (cols[j]) continue;
            
            cout << a[i][j];
        }

        cout << endl;
    }
}


