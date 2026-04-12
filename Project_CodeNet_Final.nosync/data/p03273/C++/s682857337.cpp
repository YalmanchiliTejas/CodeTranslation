#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    // ここにプログラムを追記
    // (ここで"試合結果の表"の2次元配列を宣言)
    vector<vector<char>> fig(H, vector<char>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> fig.at(i).at(j);
        }
    }
    /*    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << fig.at(i).at(j);
        }
        cout << endl;
    }*/
    int wflag;
    for (int i = 0; i < H; i++)
    {
        wflag = 0;
        for (int j = 0; j < W; j++)
        {
            if (fig.at(i).at(j) == '.')
            {
                wflag++;
            }
        }
        if (wflag == W)
        {
            for (int j = 0; j < W; j++)
            {
                fig.at(i).at(j) = '0';
            }
        }
    }
    int hflag;
    for (int j = 0; j < W; j++)
    {
        hflag = 0;
        for (int i = 0; i < H; i++)
        {
            if (fig.at(i).at(j) == '.' || fig.at(i).at(j) == '0')
            {
                hflag++;
            }
        }
        if (hflag == H)
        {
            for (int i = 0; i < H; i++)
            {
                fig.at(i).at(j) = '0';
            }
        }
    }
    int oflag;
    for (int i = 0; i < H; i++)
    {
        oflag = 0;
        for (int j = 0; j < W; j++)
        {
            if (fig.at(i).at(j) != '0')
            {
                cout << fig.at(i).at(j);
                oflag = 1;
            }
        }
        if (oflag != 0)
        {
            cout << endl;
        }
    }
}
