#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h,w;
    cin >> h >> w;

    vector<vector<char>> chars(h,vector<char>(w));

    for(int i = 0 ; i < h; ++i)
    {
        for(int j = 0 ; j < w; ++j)
        {
            char c;
            cin >> c;
            chars[i][j] = c;
        }
    }

    vector<bool> dontTakeRow(h, 0);
    vector<bool> dontTakeCol(w, 0);
    for(int i = 0 ; i < h; ++i)
    {
        int count = 0;
        for(int j = 0 ; j < w; ++j)
        {
            if(chars[i][j] == '.') count++;
        }
        if(count == w) dontTakeRow[i] = 1;
    }

    for(int i = 0 ; i < w; ++i)
    {
        int count = 0;
        for(int j = 0 ; j < h; ++j)
        {
            if(chars[j][i] == '.') count++;
        }
        if(count == h) dontTakeCol[i] = 1;
    }

    for(int i = 0 ; i < h; ++i)
    {
        bool endline = false;
        for(int j = 0 ; j < w; ++j)
        {
            if(dontTakeRow[i]==0&&dontTakeCol[j]==0)
            {
                cout << chars[i][j];
                endline = true;
            }
        }
        if(endline)cout << endl;
    }

    return 0;
}
