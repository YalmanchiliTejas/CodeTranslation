#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    int H, W;
    cin >> H >> W;

    char a[100][100];

    for (int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < W; ++j) {
            a[i][j] = s[j];
        }
    }


    for (int i = 0; i < H; ++i) {
        bool flag = true;
        for (int j = 0; j < W; ++j) {
            if (a[i][j] == '#') {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int j = 0; j < W; ++j) {
                a[i][j] = 'o';
            }
        }
    }
    for (int j = 0; j < W; ++j) {
        bool flag = true;
        for (int i = 0; i < H; ++i) {
            if (a[i][j] == '#') {
                flag = false;
                break;
            }

        }
        if (flag) {
            for (int i = 0; i < H; ++i) {
                a[i][j] = 'o';
            }
        }

    }

    for (int i = 0; i < H; ++i) {
        string s;
        for (int j = 0; j < W; ++j) {
            if (a[i][j] != 'o') {
                s += a[i][j];
            }
        }
        if (s != "") {
            cout << s << endl;
        }
    }


}
