#include <bits/stdc++.h>
using namespace std;

bool solve()
{
    int H, W; cin >> H >> W;

    vector<int> counts(H+W-1);

    for (int r = 0; r < H; r++)
    {
        string row; cin >> row;
        for (int c = 0; c < W; c++)
            if (row[c] == '#')
                counts[r+c]++;
    }

    for (const int x : counts)
        if (x != 1)
            return false;
    return true;
}

int main()
{
    cout << (solve() ? "Possible" : "Impossible") << endl;
}
