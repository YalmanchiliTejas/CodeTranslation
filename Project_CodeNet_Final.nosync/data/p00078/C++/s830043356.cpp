#include <iostream>
#include <cstdio>
using namespace std;

void arrange(int& i, int n) {
    if (i >= n) {
        i = 0;
    } else if (i < 0) {
        i = n - 1;
    }
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        int** square = new int* [n];
        for (int i = 0; i < n; i++) {
            square[i] = new int [n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                square[i][j] = 0;
            }
        }
        int x = n / 2;
        int y = 1 + n / 2;
        for (int i = 0; i < n * n; ) {
            arrange(x, n);
            arrange(y, n);
            if (square[y][x] == 0) {
                square[y++][x++] = i++ + 1;
            } else {
                x--;
                y++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%4d", square[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < n; i++) {
            delete[] square[i];
        }
        delete[] square;
    }
}