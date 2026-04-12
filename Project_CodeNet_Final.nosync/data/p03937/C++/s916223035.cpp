#include <bits/stdc++.h>
using namespace std;

int main()
{
    int R, C; cin >> R >> C;

    auto grid = vector<string>(R);
    for (auto& row : grid) cin >> row;

    auto trace = vector<string>(R);
    for (auto& row : trace) row = string(C, '.');

    auto r = 0, c = 0;
    while (true)
    {
        trace[r][c] = '#';
        if (r == R-1 && c == C-1) break;
        else if (r != R-1 && grid[r+1][c] == '#') r++;
        else if (c != C-1 && grid[r][c+1] == '#') c++;
        else break;
    }

    cout << (grid == trace ? "Possible" : "Impossible") << endl;
}
