#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

int main(void) {
    i64 h, w, ans = true;
    cin >> h >> w;
    i64 e[16][2];
    for (i64 i = 0; i < h; i++) {
        e[i][0] = e[i][1] = -1;
        string a;
        cin >> a;
        for (i64 j = 0; j < w; j++) {
            if (e[i][1] != -1 && a[j] == '#') ans = false;
            if (e[i][0] == -1 && a[j] == '#') e[i][0] = j;
            if (e[i][0] != -1 && e[i][1] == -1
                && a[j] == '.') e[i][1] = j - 1;
        }
        if (e[i][1] == -1) e[i][1] = w - 1;
        //cout << e[i][0] << ' ' << e[i][1] << endl;
    }
    for (i64 i = 1; i < h; i++) {
        if (e[i][0] != e[i - 1][1]) ans = false;
    }
    cout << (ans ? "Possible" : "Impossible") << endl;
}