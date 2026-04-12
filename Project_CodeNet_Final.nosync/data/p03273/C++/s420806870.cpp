#include <iostream>
#include <string>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    string s[h];
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    bool bh[h];
    for (int i = 0; i < h; i++) {
        bh[i] = true;
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                bh[i] = false;
                break;
            }
        }
    }

    bool bw[w];
    for (int i = 0; i < w; i++) {
        bw[i] = true;
        for (int j = 0; j < h; j++) {
            if (s[j][i] == '#') {
                bw[i] = false;
                break;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        if (bh[i]) {
            continue;
        }
        for (int j = 0; j < w; j++) {
            if (!bw[j]) {
                cout << s[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}