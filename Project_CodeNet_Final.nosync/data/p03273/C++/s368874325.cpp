#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define imfor(i, n) for(int i = 0; i < n; i++)
using namespace std;
ll MOD = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    char a[110][110];
    imfor(i, h) {
        imfor(j, w) {
            cin >> a[i][j];
        }
    }
    int rows[110];
    int cols[110];
    fill(rows, rows + 100, 0);
    fill(cols, cols + 100, 0);
    imfor(i, h) {
        bool f = true;
        imfor(j, w) {
            if (a[i][j] == '#') {
                f = false;
                break;
            }
        }
        if (f) {
            rows[i] = 1;
        }
    }
    imfor(i, w) {
        bool f = true;
        imfor(j, h) {
            if (a[j][i] == '#') {
                f = false;
                break;
            }
        }
        if (f) {
            cols[i] = 1;
        }
    }

    imfor(i, h) {
        if (rows[i] == 1) {
            continue;
        }
        bool f = true;
        imfor(j, w) {
            if (cols[j] == 0) {
                cout << a[i][j];
                f = false;
            }
        }
        if (!f) {
            cout << endl;
        }
    }
}