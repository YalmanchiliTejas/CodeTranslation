#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<vector<int> > grid(a, vector<int>(b));
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            char c;
            cin >> c;
            grid[i][j] = (c == '#');
        }
    }
    vector<int> col (b, 1);
    vector<int> row(a, 1);
        for (int i = 0; i < grid.size(); i++) {
            int ta = 0;
            for (int j = 0; j < grid[i].size(); j++) {
                ta += grid[i][j];
            }
            if ( ta == 0) {
                    row[i] = 0;
            }
        }
        for (int i = 0; i < grid[0].size(); i++) {
            int ta = 0;
            for (int j = 0; j < grid.size(); j++) {
                ta += grid[j][i];
            }
            if (ta == 0) {
                col[i] = 0;
            }
        }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (row[i] && col[j])
                if (grid[i][j] == 1)
                    cout << '#';
                else
                    cout << '.';
    }   if(!row[i])
            continue;
        cout << endl;
    }
}
