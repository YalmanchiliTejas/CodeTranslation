#include <iostream>
#include <cstdio>
using namespace std;

inline int adjust(int x, int n) {
    if (x < 0) {
        return n - 1;
    }
    else if (x >= n) {
        return x % n;
    }
    return x;
}

int main() {
    int n;
    while (cin >> n, n) {
        int s[15][15] = {0};
        int r, c, m, n2;
        r = n / 2 + 1;
        c = n / 2;
        s[r][c] = 1;
        m = 2;
        n2 = n * n;
        while (m <= n2) {
            r = adjust(r + 1, n);
            c = adjust(c + 1, n);
            while (s[r][c] > 0) {
                r = adjust(r + 1, n);
                c = adjust(c - 1, n);
            }
            s[r][c] = m;
            m++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%4d", s[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}