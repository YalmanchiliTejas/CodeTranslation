#include <bits/stdc++.h>
using namespace std;

bool isWhite(string str)
{
    regex re(R"(\.+)");
    return regex_match(str, re);
}
vector<string> delRows(vector<string> vec)
{
    vector<string> shrinked;
    for (string row : vec)
    {
        if (!isWhite(row))
        {
            shrinked.emplace_back(row);
        }
    }
    return shrinked;
}
vector<string> delCols(vector<string> vec)
{
    int rowNum = vec.size();
    int colNum = vec[0].size();
    vector<string> shrinked;
    vector<bool> blackIndex(colNum, false);
    for (int i = 0; i < colNum; ++i)
    {
        string col = "";
        for (string row : vec)
        {
            col += row[i];
        }
        if (!isWhite(col))
        {
            blackIndex[i] = true;
        }
    }
    for (int i = 0; i < rowNum; ++i)
    {
        string tmp = "";
        for (int j = 0; j < colNum; ++j)
        {
            if (blackIndex[j])
            {
                tmp += vec[i][j];
            }
        }
        shrinked.emplace_back(tmp);
    }
    return shrinked;
}

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> vec(H);
    for (int i = 0; i < H; ++i)
    {
        cin >> vec.at(i);
    }
    vec = delRows(vec);
    vec = delCols(vec);
    H = vec.size();
    for (int i = 0; i < H; ++i)
    {
        cout << vec.at(i);
        if (i < H)
        {
            cout << endl;
        }
    }
}