#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h,w;
    cin>>h>>w;
    vector<vector<char>> table(h,vector<char>(w));
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>table.at(i).at(j);
        }
    }
    vector<bool>gyou(h);
    vector<bool>retu(w);
    for(int i=0;i<h;i++)
    {
        bool flg = true;
        for(int j=0;j<w;j++)
        {
            if(table.at(i).at(j) == '.')
            {
                flg = flg && true;
            }else{
                flg = flg && false;
            }
        }
        gyou.at(i) = flg;
    }
    for(int i=0;i<w;i++)
    {
        bool flg = true;
        for(int j=0;j<h;j++)
        {
            if(table.at(j).at(i) == '.')
            {
                flg = flg && true;
            }else{
                flg = flg && false;
            }
        }
        retu.at(i) = flg;
    }
    for(int i=0;i<h;i++)
    {
        if(gyou.at(i))
        {
            continue;
        }else{
            for(int j=0;j<w;j++)
            {
                if(retu.at(j))
                {
                    continue;
                }else{
                    cout<<table.at(i).at(j);
                }
            }
        }
        cout<<endl;
    }
}