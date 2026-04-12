#include <iostream>
#include <vector>

using namespace std;
int main()
{
    //要素数入力
    int H, W;
    cin >> H >> W;

    //データ入力
    vector<vector<char>> grid(H, vector<char>(W, '-'));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> grid.at(i).at(j);
        }
    }

    int a[100];
    for (int i = 0; i < 100; i++)
    {
        a[i] = 0;
    }
    //まず行を調べる
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (grid.at(i).at(j) == '.' || grid.at(i).at(j) == '-')
            {
                a[i]++;
            }
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (a[i] == W)
            {
                grid.at(i).at(j) = '-';
            }
        }
    }

    int b[100];
    for (int i = 0; i < 100; i++)
    {
        b[i] = 0;
    }
    //次に列を調べる
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (grid.at(j).at(i) == '.' || grid.at(j).at(i) == '-')
            {
                b[i]++;
            }
        }
    }
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (b[i] == H)
            {
                grid.at(j).at(i) = '-';
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (grid.at(i).at(j) != '-')
            {
                cout << grid.at(i).at(j);
            }
        }
        if (a[i] != W && b[W] != H){
            cout << "" << endl;
        }
    }
}