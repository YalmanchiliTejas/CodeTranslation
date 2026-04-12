#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }        
    }
    vector<int> raw, column;

    rep(i, h) {
        int flag = true;
        rep(j, w) {
            if (a[i][j] != '.') {
                flag = false;
                break;
            }
        }

        if (flag) raw.push_back(i);
    }

    rep(j, w) {
        int flag = true;
        rep(i, h) {
            if (a[i][j] != '.') {
                flag = false;
                break;
            }
        }

        if (flag) column.push_back(j);
    }

    rep(i, h) {
        int flagr = false;
        for (auto x : raw) {
            if (x == i) {
                flagr = true;
                break;
            }
        }

        if (flagr) continue;

        rep(j, w) {
            int flagc = false;
            for (auto y : column) {
                if (y == j) {
                    flagc = true;
                }
            }

            if (flagc) continue;

            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}