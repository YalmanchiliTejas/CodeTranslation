#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int h, w;
    string tmp;
    int flag = 0;
    cin >> h >> w;
    vector<string> data(h);
    vector<vector<char> > r(w, vector<char>(h));
    vector<vector<char> > rr(h, vector<char>(w));

    // データを挿入
    for (int i = 0; i < h; i++)
    {
        cin >> data.at(i);
    }

    // 横列全部白のものを削除
    int k = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (data.at(i)[j] == '.')
            {
                continue;
            }
            if (data.at(i)[j] == '#')
            {
                flag++;
            }
        }
        // cout << "debug" << endl;
        if (flag > 0)
        { // 同じでなかったらデータを入れる
            for (int j = 0; j < w; j++)
            {
                r.at(j).at(k) = data.at(i)[j]; // 縦と横を回転
            }
            k++;
        }
        flag = 0;
    }
    // cout << endl;
    // cout << "w: "<< w <<" k: "<< k << endl;
    // // debug
    // for (int i = 0; i < w; i++)//最後にk++する分をマイナスする
    // {
    //     for (int j = 0; j < k; j++)
    //     {
    //         cout << r.at(i).at(j);
    //     }
    //     cout << endl;
    // }

    // 縦列全部白のものを削除
    int l = 0;
    for (int i = 0; i < w; i++)
    {
        flag = 0;
        for (int j = 0; j < k; j++)
        {
            if (r.at(i).at(j) == '.')
            {
                continue;
            }
            if (r.at(i).at(j) == '#')
            {
                flag++;
            }
        }
        if (flag > 0)
        { // 同じでなかったらデータを入れる
            for (int j = 0; j < k; j++)
            {
                rr.at(j).at(l) = r.at(i).at(j); // 縦と横を回転
            }
            l++;
        }
    }
    // cout << "l: "<< l <<" k: "<< k << endl;

    // 表示
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cout << rr.at(i).at(j);
        }
        cout << endl;
    }
}
