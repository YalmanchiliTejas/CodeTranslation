#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a.at(i);

    rep(i, h)
    {
        bool is_all_white = true;
        rep(j, w)
        {
            if (a.at(i).at(j) == '#')
            {
                is_all_white = false;
            }
        }
        if (is_all_white)
        {
            rep(j, w)
            {
                a.at(i).at(j) = '-';
            }
        }
    }
    rep(j, w)
    {
        bool is_all_white = true;
        rep(i, h)
        {
            if (a.at(i).at(j) == '#')
            {
                is_all_white = false;
            }
        }
        if (is_all_white)
        {
            rep(i, h)
            {
                a.at(i).at(j) = '-';
            }
        }
    }

    int answer = 0;
    rep(i, h)
    {
        bool is_write = false;
        rep(j, w)
        {
            if (a.at(i).at(j) != '-')
            {
                cout << a.at(i).at(j);
                is_write = true;
            }
        }
        if (is_write)
        {
            cout << endl;
        }
    }
}