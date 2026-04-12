#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <bitset>
#include <cassert>

using namespace std;

char w[10][10];
int id1[10];
int id2[10];

void exit_() {
    cout << "Impossible\n";
    exit(0);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> w[i][j];
    if (w[0][0] != '#' || w[n - 1][m - 1] != '#') {
        exit_();
    }
    for (int i = 0; i < n; ++i) {
        int j = 0;
        while (j < m && w[i][j] == '.')
            ++j;
        if (j == m) {
            exit_();
        }
        id1[i] = j;
        while (j < m && w[i][j] == '#')
            ++j;
        --j;
        id2[i] = j;
        for (j = j + 1; j < m; ++j)
            if (w[i][j] == '#') {
                exit_();
            }
    }
    for (int i = 1; i < n; ++i)
        if (id1[i] != id2[i - 1]) {
            exit_();
        }
    cout << "Possible\n";
}