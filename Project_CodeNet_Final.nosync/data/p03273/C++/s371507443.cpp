#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int ctoi(char);

int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<char>> sq(H, vector<char>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            char x;
            cin >> x;
            sq.at(i).at(j) = x;
        }
    }
    // cout << "sec1" << endl;
    vector<int> delete_list_1;
    rep(i, sq.size())
    {
        rep(j, sq.at(i).size())
        {
            if (sq.at(i).at(j) == '#')
            {
                break;
            }
            if (j == sq.at(i).size() - 1)
            {
                delete_list_1.push_back(i);
            }
        }
    }
    for (int i = delete_list_1.size() - 1; i >= 0; i--)
    {
        sq.erase(sq.begin() + delete_list_1.at(i));
    }
    // cout << "sec2" << endl;
    vector<int> delete_list_2;
    rep(j, sq.at(0).size())
    {
        rep(i, sq.size())
        {
            if (sq.at(i).at(j) == '#')
            {
                break;
            }
            if (i == sq.size() - 1)
            {
                delete_list_2.push_back(j);
            }
        }
    }
    for (int j = delete_list_2.size() - 1; j >= 0; j--)
    {
        rep(i, sq.size())
        {
            sq.at(i).erase(sq.at(i).begin() + delete_list_2.at(j));
        }
    }
    // cout << "sec3" << endl;
    for (vector<char> cs : sq)
    {
        for (char c : cs)
        {
            cout << c;
        }
        cout << endl;
    }
}

int ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return -1;
}
