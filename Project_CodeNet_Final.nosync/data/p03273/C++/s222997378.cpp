#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> board(H, vector<char>(W));
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cin >> board[i][j];
        }
    }

    vector<vector<char>> rows;
    for (const auto &row : board)
    {
        if (find(row.begin(), row.end(), '#') != row.end())
        {
            rows.push_back(row);
        }
    }

    vector<int> colIndices;
    for (int col = 0; col < W; ++col)
    {
        bool shouldAdd = false;
        for (int i = 0, n = static_cast<int>(rows.size()); i < n; ++i)
        {
            if (rows[i][col] == '#')
            {
                shouldAdd = true;
                break;
            }
        }
        if (shouldAdd)
        {
            colIndices.push_back(col);
        }
    }

    vector<string> ans;
    for (const auto &row : rows)
    {
        string ansRow;
        for (const int &col : colIndices)
        {
            ansRow.push_back(row[col]);
        }
        ans.push_back(ansRow);
    }

    for (const auto ansRow : ans)
    {
        cout << ansRow << endl;
    }
}