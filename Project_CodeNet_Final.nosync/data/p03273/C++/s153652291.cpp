#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int h,w;
    cin>> h>>w;

    vector<vector<char>> grid(h,vector<char>(w));
    vector<bool> hisw(h,0);
    vector<bool> wisw(w,0);

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>grid.at(i).at(j);
        }
    }

    for(int i=0;i<h;i++)
    {
        bool isw=1;
        for(int j=0;j<w;j++)
        {
            if(grid.at(i).at(j)=='#')
            {
                isw=0;
                break;
            }
        }
        if (isw)
        hisw.at(i) = 1;
    }

    for(int j=0;j<w;j++)
    {
        bool isw=1;
        for(int i=0;i<h;i++)
        {
            if(grid.at(i).at(j)=='#')
            {
                isw=0;
                break;
            }
        }
        if(isw)
        wisw.at(j) =1;
    }

    for(int i=0;i<h;i++)
    {
        if(hisw.at(i))
        continue;
        for(int j=0;j<w;j++)
        {
            if(!wisw.at(j))
            cout<<grid.at(i).at(j);
        }
        cout<<endl;
    }
}