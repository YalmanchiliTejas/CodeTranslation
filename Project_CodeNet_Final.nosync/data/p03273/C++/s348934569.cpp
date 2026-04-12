#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    char A[100][100];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> A[i][j];
        }
    }

    set<int> R, C;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (A[i][j] == '#') {
                R.insert(i);
                C.insert(j);
            }
        }
    }

    for (set<int>::iterator it_i = R.begin(); it_i != R.end(); it_i++) {
        for (set<int>::iterator it_j = C.begin(); it_j != C.end(); it_j++) {
            cout << A[*it_i][*it_j];
        }
        cout << endl;
    }

    return 0;
}
