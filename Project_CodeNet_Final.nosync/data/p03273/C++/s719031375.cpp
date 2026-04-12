#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()

{

    int h, w;
    cin >> h >> w;
    char a[h][w];
    int row[w];
    int col[h];
    /*初期化*/
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            a[i][j] = '-';
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; i++)
    {
        col[i] = 0;
    }
    for (int i = 0; i < w; i++)
    {
        row[i] = 0;
    }
    //初期化おわり

    for (int i = 0; i < h; i++)
    {
        int count = 0;
        for (int j = 0; j < w; j++)
        {
            if (a[i][j] == '#')
            {
                count = 1;
            }
        }
        if (count == 0)
        {
            col[i] = 1;
        }
    }

    for (int i = 0; i < w; i++)
    {

        int count = 0;
        for (int j = 0; j < h; j++)
        {
            if (a[j][i] == '#')
            {
                count = 1;
            }
        }
        if (count == 0)
        {
            row[i] = 1;
        }
    }

    //  cout << "-------------^\n";
    for (int i = 0; i < h; i++)
    {

        int count = 0;
        for (int j = 0; j < w; j++)
        {
            if (col[i] == 0 && row[j] == 0)
            {
                cout << a[i][j];
                count = 1;
            }
        }
        if (count == 1)
        {
            cout << "\n";
        }
    }
    /*
    cout << "col-------------\n";
    for (int i = 0; i < h; i++)
    {
        cout << col[i];
    }
    cout << "row--------------\n";
    for (int i = 0; i < w; i++)
    {
        cout << row[i];
    }*/
}
