#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
#include <string>
#include <stack>
#include <tuple>
#include <queue>
#include <functional>
#include <unordered_map>
#include <random>
#include <iomanip>

using namespace std;
typedef long long ll;
ll MOD = 1e9 + 7;

vector<int> dRow = { 1,0,-1, 0 };
vector<int> dCol = { 0,1, 0, -1 };
int main()
{
    int height, width;
    cin >> height >> width;
    vector<string> field(height);
    for (int row = 0; row < height; row++) cin >> field[row];
    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(0, 0, -1 ,-1));
    while (!q.empty())
    {
        bool isNext = false;
        int curRow, curCol, prevRow, prevCol;
        tie(curRow, curCol, prevRow, prevCol) = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nextRow = curRow + dRow[dir];
            int nextCol = curCol + dCol[dir];
            if (nextRow < 0 || nextRow >= height || nextCol < 0 || nextCol >= width || (nextRow == prevRow && nextCol == prevCol)) continue;
            if (dir < 2)
            {
                if (field[nextRow][nextCol] == '#')
                {
                    isNext = true;
                    q.push(make_tuple(nextRow, nextCol,curRow,curCol));
                }
            }
            else if (field[nextRow][nextCol] == '#')
            {
                cout << "Impossible" << endl;
                return 0;
            }
        }
        if (!isNext && (curRow != height - 1 || curCol != width - 1))
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;
}