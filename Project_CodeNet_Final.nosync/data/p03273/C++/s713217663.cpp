#include <iostream>
#include <string>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
    int h, w;
    string a[100];
    bool col[100] = {false}, row[100] = {false};

    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    REP(i, h) {
        cin >> a[i];
        REP(j, w) {
            if (a[i][j] == '#') {
                col[i] = true;
                row[j] = true;
            }
        }
    }

    REP(i, h) {
        if (col[i]) {
            REP(j, w) {
                if (row[j]) {
                    cout << a[i][j];
                }
            }
            cout << "\n";
        }
    }

    return 0;
}