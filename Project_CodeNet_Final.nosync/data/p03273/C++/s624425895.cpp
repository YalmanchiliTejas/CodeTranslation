#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int i, j;
    int h, w; cin >> h >> w;
    bool consecutive = true;
    vector<int> row_index(1, -1);
    vector<vector<char>> board(h, vector<char>(w));
    for (i=0; i<h; i++)
    {
        for (j=0; j<w; j++)
        {
            cin >> board.at(i).at(j);
        }
    }

    for (i=0; i<h; i++)
    {
        consecutive = true;
        for (j=0; j<w; j++)
        {
            if (board.at(i).at(j) == '#') consecutive = false;
        }

        if (consecutive)
        {
            row_index.push_back(i);
            for (j=0; j<w; j++)
            {
                board.at(i).at(j) = 'n';
            }
        }
    }

    for (i=0; i<w; i++)
    {
        consecutive = true;
        for (j=0; j<h; j++)
        {
            if (board.at(j).at(i) == '#') consecutive = false;
        }

        if (consecutive)
        {
            for (j=0; j<h; j++)
            {
                board.at(j).at(i) = 'n';
            }
        }
    }

    bool row = true;
    for (i=0; i<h; i++)
    {
        row = true;
        for (j=0; j<w; j++)
        {
            for (int x : row_index) if (x == i) {row = false; break;}
            if (board.at(i).at(j) != 'n')
            {
                cout << board.at(i).at(j);
            }
        }
        if (row) cout << endl;
    }
}

