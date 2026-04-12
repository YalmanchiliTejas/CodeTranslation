#include <iostream>
#include <string>
using namespace std;

int main() {
    int h, w;
    char mp[105][105];
    int Xsum[105] = {};
    int Ysum[105] = {};

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == '#') {
                Xsum[i]++;
                Ysum[j]++;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        int f = 0;
        for (int j = 0; j < w; j++) {
            if (Xsum[i] != 0 && Ysum[j] != 0) {
                cout << mp[i][j];
                f = 1;
            }
        }
        if (f) cout << endl;
    }

    return 0;
}