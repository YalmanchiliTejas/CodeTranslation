#include <iostream>
using namespace std;
#include <vector>

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> table(h, vector<char>(w));

    vector<bool> hd(h, 0);
    vector<bool> wd(w, 0);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> table[i][j];
            if (table[i][j] == '#') {
                hd[i] = 1;
                wd[j] = 1;
            }
        }
    }

    vector<vector<char>> ans(h, vector<char>(w));
    int ansi = 0, ansj = 0;

    for (int i = 0; i < h; i++) {
        if (hd[i] == 1) {
            ansj = 0;
            for (int j = 0; j < w; j++) {
                if (wd[j] == 1) {
                    ans[ansi][ansj] = table[i][j];
                    ansj++;
                }
            }
            ansi++;
        }
    }

    for (int i = 0; i < ansi; i++) {
        for (int j = 0; j < ansj; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }

}