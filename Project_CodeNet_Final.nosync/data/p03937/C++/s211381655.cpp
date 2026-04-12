#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> table(h);
    for (auto& row : table)
    {
        cin >> row;
    }
    // vector<vector<int64_t>> dp(h, vector<int64_t>(w, 0));
    // dp[0][0] = 1;
    // for (int i = 1; i < h; i++)
    // {
    //     if (table[i][0] == '#')
    //     {
    //         dp[i][0] = dp[i - 1][0];
    //     }
    // }
    // for (int i = 1; i < w; i++)
    // {
    //     if (table[0][i] == '#')
    //     {
    //         dp[0][i] = dp[0][i - 1];
    //     }
    // }

    // for (int i = 1; i < h; i++)
    // {
    //     for (int j = 1; j < w; j++)
    //     {
    //         if (table[i][j] == '#')
    //         {
    //             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    //         }
    //     }
    // }

    int count = 0;
    for (auto& row : table)
    {
        for (auto& elem : row)
        {
            if (elem == '#')
            {
                count++;
            }
        }
    }

    cout << (count == (h + w - 1) ? "Possible" : "Impossible") << endl;
}
