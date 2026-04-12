#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void)
{
    int h, w;
    char a[101][101] = {0};
    char b[101][101] = {0};
    char c[101][101] = {0};

    cin >> h >> w;
    
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }

    int bi = 1;
    for (int i = 1; i <= h; i++) {
        int count_row = 0;
        for (int j = 1; j <= w; j++) {
            if (a[i][j] == '.') {
                count_row++;
            }
            b[bi][j] = a[i][j];
        }
        if (count_row != w) {
            bi++;
        }
    }
    bi--;

    int bj = 1;
    for (int j = 1; j <= w; j++) {
        int count_column = 0;
        for (int i = 1; i <= bi; i++) {
            if (b[i][j] == '.') {
                count_column++;
            }
            c[i][bj] = b[i][j];
        }
        if (count_column != bi) {
            bj++;
        }
    }
    bj--;

    for (int i = 1; i <= bi; i++) {
        for (int j = 1; j <= bj; j++) {
            cout << c[i][j];
        }
        cout << endl;
    }
    
    return 0;
}