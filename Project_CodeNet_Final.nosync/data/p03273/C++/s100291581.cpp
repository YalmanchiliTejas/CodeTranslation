#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int> (m));
    vector<int> row(n);
    vector<int> column(m);
    char c;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> c;
            if (c == '#') {
                grid[i][j] = 1;
                row[i]++;
                column[j]++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if (row[i] != 0) {
            for(int j = 0; j < m; j++) {
                if(column[j] != 0) {
                    if (grid[i][j] == 0) {
                        cout << ".";
                    } else {
                        cout << "#";
                    }
                }
            }
            cout << endl;
        }
    }
}