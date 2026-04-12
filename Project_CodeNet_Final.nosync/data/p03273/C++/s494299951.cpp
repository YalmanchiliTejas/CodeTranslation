#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h,w;
    cin >> h >> w;
    char a[h][w];
    vector<int> v1,v2;
    for(int i = 0;i < h;i++)
    {
        for(int j = 0;j < w;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0;i < h;i++)
    {
        bool flag = true;
        for(int j = 0;j < w;j++)
        {
            if(a[i][j] == '#')
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            v1.push_back(i);
        }
    }
    for(int j = 0;j < w;j++)
    {
        bool flag = true;
        for(int i = 0;i < h;i++)
        {
            if(a[i][j] == '#')
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            v2.push_back(j);
        }
    }
    for(int i = 0;i < h;i++)
    {
        bool flag1 = true;
        for(int k = 0;k < v1.size();k++)
        {
            if(v1.at(k) == i)
            {
                flag1 = false;
                break;
            }
        }
        if(flag1)
        {
            for(int j = 0;j < w;j++)
            {
                bool flag2 = true;
                for(int k = 0;k < v2.size();k++)
                {
                    if(v2.at(k) == j)
                    {
                        flag2 = false;
                    }
                }
                if(flag2)
                {
                    cout << a[i][j];
                }
            }
            cout << "\n";
        }
    }

    return 0;
}