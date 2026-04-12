#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> vec(h);

    for (int i = 0; i < h; i++)
    {
        cin >> vec[i];
    }

    // 出力する行と列を判定する
    vector<bool> column(h); // 列
    vector<bool> row(w);    // 行

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (vec[i][j] == '#')
            {
                column[i] = true;
                row[j] = true;
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        if (!column[i])
            continue;
        for (int j = 0; j < w; j++)
        {
            if (!row[j])
                continue;
            cout << vec[i][j];
        }
        cout << endl;
    }
}