#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    vector<int> r, c;
    for (int i = 0; i < h; i++) {
        bool f = false;
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                f = true;
                break;
            }
        }

        if (f) {
            r.push_back(i);
        }
    }

    for (int j = 0; j < w; j++) {
        bool f = false;
        for (int i = 0; i < h; i++) {
            if (s[i][j] == '#') {
                f = true;
                break;
            }
        }

        if (f) {
            c.push_back(j);
        }
    }

    for (int i : r) {
        for (int j : c) {
            cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}