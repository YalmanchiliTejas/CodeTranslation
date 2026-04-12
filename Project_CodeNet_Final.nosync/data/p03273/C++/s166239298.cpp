#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>());

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            char tmp;
            cin >> tmp;

            grid[i].push_back(tmp);
            // cout << i << " " << j << " " << tmp << " " << grid.at(i).at(j) << "\n";
        }
    }

    vector<bool> row(H, false);
    vector<bool> col(W, false);
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (grid[i][j] == '#') {
                row[i] = true;
                col[j] = true;
                // cout << "row" << i << " " << row[i] << " col" << j << " " << col[j] << "\n";
            }
        }
    }

    for (int i=0; i<H; i++) {
        if (row[i] == true) {
            for (int j=0; j<W; j++) {
                if (col[j] == true) {
                    cout << grid[i][j];
                }
            }
            cout << "\n";
        }
    }

    return 0;
}
