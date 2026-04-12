#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> x(h, vector<char>(w));
    vector<vector<char>> y(h, vector<char>(w));
    vector<vector<char>> z(h, vector<char>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> x.at(i).at(j);
        }
    }
    int count=0;

    //縦を圧縮
    int iii = 0;
    for (int i = 0; i < h; i++)
    {
        count = 0;
        for (int j = 0; j < w; j++)
        {
            if (x.at(i).at(j) == '.')
            {
                count++;
            }
        }
        if (count != w)
        {
            for (int j = 0; j < w; j++)
            {
                y.at(iii).at(j) = x.at(i).at(j);
            }
            iii++;
        }
     // cout<<count<<endl;
      count=0;
    }

    //横を圧縮
    int jjj = 0;
    for (int j = 0; j < w; j++)
    {
        count = 0;
        for (int i = 0; i < iii; i++)
        {
            if (y.at(i).at(j) == '.')
            {
                count++;
            }
        }
        if (count != iii)
        {
            for (int i = 0; i < iii; i++)
            {
                z.at(i).at(jjj) = y.at(i).at(j);
            }
            jjj++;
        }
    //  cout<<count<<endl;
      count=0;
    }

    for (int i = 0; i < iii; i++)
    {
        for (int j = 0; j < jjj; j++)
        {
            cout << z.at(i).at(j);
        }
        cout<<endl;
    }
 // cout<<iii<<jjj<<endl;

}
