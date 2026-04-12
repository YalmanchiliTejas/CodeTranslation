#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(void) {
    int n;
    while (cin >> n) {
        if (n == 0) break;

        vector<vector<int> > masu(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                masu[i].push_back(0);
            }
        }

        int num = 2;
        int dx = n/2+1, dy = n/2;
        masu[dx][dy] = 1;
        while (num <= n*n) {
            dx = (dx+1)%n; dy = (dy+1)%n;
            if (masu[dx][dy] == 0) {
                masu[dx][dy] = num;
            } else {
                do {
                    dx = (dx+1)%n;
                    dy--; if (dy == -1) dy = n-1;
                    if (masu[dx][dy] == 0) {
                        masu[dx][dy] = num;
                    }
                } while (masu[dx][dy] != num);
            }
            num++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << right << setw(4) << masu[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}