#include <iostream>

using namespace std;

int R,C;
string grid[10];

int main() {
    ios::sync_with_stdio(0);
    cin >> R >> C;
    for(int i = 0; i < R; ++i)
        cin >> grid[i];
    if(grid[0][0] != '#' || grid[R-1][C-1] != '#')
        grid[R-1][C-1] = 'X';
    int r=0,c=0;
    grid[0][0] = '.';
    while(r != R-1 || c != C-1) {
        if(r+1 < R && grid[r+1][c] == '#') {
            r+=1;
        } else if(c+1 < C && grid[r][c+1] == '#') {
            c+=1;
        } else {
            break;
        }
        grid[r][c] = '.';
    }
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(grid[i][j] != '.') {
                cout << "Impossible\n";
                return 0;
            }
        }
    }
    cout << "Possible\n";
    return 0;
}