#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;

    vector<string> a(h);

    vector<bool> delx(w,false);
    vector<bool> dely(h,false);

    int i,j;
    for (i = 0; i < h; i++)
    {
        cin >> a[i];
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if(a[i][j] == '#')break;
        }
        if(j == w)dely[i] = true;
    }

    for (i = 0; i < w; i++)
    {
        for (j = 0; j < h; j++)
        {
            if(a[j][i] == '#')break;
        }
        if(j == h)delx[i] = true;
    }

    for (i = 0; i < h; i++)
    {
        if(dely[i])continue;
        for (j = 0; j < w; j++)
        {
            if(delx[j])continue;
            cout << a[i][j];
        }
        cout << endl;
    }
}