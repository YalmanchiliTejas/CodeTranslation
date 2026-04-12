#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w; cin >> h >> w;
    vector<string> s(h);
    for (auto &si: s) cin >> si;
    vector<bool> need_row(h), need_col(w);
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
        if (s[i][j] == '#') need_row[i] = need_col[j] = true;
    }
    for (int i = 0; i < h; i++) if (need_row[i]) {
        for (int j = 0; j < w; j++) if (need_col[j]) cout << s[i][j];
        cout << endl;
    }
    return 0;
}
