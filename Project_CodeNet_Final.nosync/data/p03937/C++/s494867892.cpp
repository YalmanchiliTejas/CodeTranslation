
#include <iostream>
#include <string>

using namespace std;

int H, W;
string grid[10];
bool marked[10][10];

bool solve() {
    int curi = 0, curj = 0;
    while (true) {
        marked[curi][curj] = true;
        if (grid[curi][curj] != '#')
            return false;
        if (curi == H - 1 && curj == W - 1)
            break;
        bool movei = curi + 1 < H && grid[curi + 1][curj] == '#';
        bool movej = curj + 1 < W && grid[curi][curj + 1] == '#';
        if (movei && movej)
            return false;
        if (!movei && !movej)
            return false;
        if (movei)
            curi++;
        if (movej)
            curj++;
    }
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (grid[i][j] == '#' && !marked[i][j])
                return false;
    return true;
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++)
        cin >> grid[i];

    if (solve())
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
}
