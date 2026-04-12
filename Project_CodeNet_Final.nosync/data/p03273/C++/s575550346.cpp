#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int h, w;
    char a[100][100];

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        bool result = all_of(&a[i][0], &a[i][w], [](char c) {
                return c == '.';
            });
        if (result) {
            for (int j = 0; j < w; j++) {
                a[i][j] = ' ';
            }
        }
    }

    for (int j = 0; j < w; j++) {
        bool result = true;
        for (int i = 0; i < h; i++) {
            if (a[i][j] == '#') {
                result = false;
                break;
            }
        }
        if (result) {
            for (int i = 0; i < h; i++) {
                a[i][j] = ' ';
            }
        }
    }

    for (int i = 0; i < h; i++) {
        bool valid = false;
        for (int j = 0; j < w; j++) {
            if (a[i][j] != ' ') {
                cout << a[i][j];
                valid = true;
            }
        }
        if (valid) {
            cout << endl;
        }
    }

    return 0;
}
