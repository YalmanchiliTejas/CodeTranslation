#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

bool has_only_one_char(vector<char> cv) {
    set<char> cs;
    for (int i = 0; i < cv.size(); i++) {
        cs.insert(cv[i]);
    }

    return cs.size() == 1;
}

void solve() {
    int h, w;
    cin >> h >> w;

    set<int> include_black_row, include_black_col;

    char a[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                include_black_row.insert(i);
                include_black_col.insert(j);
            }
        }
    }

    bool outputed;
    for (int i = 0; i < h; i++) {
        outputed = false;
        for (int j = 0; j < w; j++) {
            if (include_black_row.find(i) != include_black_row.end() && include_black_col.find(j) != include_black_col.end()) {
                cout << a[i][j];
                outputed = true;
            }
        }
        if (outputed) cout << endl;
    }
}

int main() {
    solve();

    return 0;
}
