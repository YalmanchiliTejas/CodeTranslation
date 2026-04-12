#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

string str[20];

int main() {
    //ifstream cin("f.in");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) {
        cin >> str[i];
        str[i] = " " + str[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            if (str[i][j] == '#') {
                cnt += 1;
            }
        }
    }
    if (cnt != n + m - 1) {
        cout << "Impossible\n";
        return 0;
    }
    int x = 1, y = 1;
    while (x != n || y != m) {
        if (x == n) {
            if (str[x][y + 1] != '#') {
                cout << "Impossible\n";
                return 0;
            }
            y += 1;
        } else if (y == m) {
            if (str[x + 1][y] != '#') {
                cout << "Impossible\n";
                return 0;
            }
            x += 1;
        } else {
            if (str[x][y + 1] == '#') {
                y += 1;
            } else if (str[x + 1][y] == '#') {
                x += 1;
            } else {
                cout << "Impossible\n";
                return 0;
            }
        }
    }
    cout << "Possible\n";
    return 0;
}
