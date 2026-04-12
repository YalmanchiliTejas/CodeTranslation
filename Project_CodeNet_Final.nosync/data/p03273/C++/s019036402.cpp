#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int h,w,i,j,no=1,tmp=0,tc=0,tr=0,p;
    cin >> h >> w;
    int r[h+1];
    int c[w+1];
    for(i=0;i<h+1;i++)
        r[i] = -1;
    for(i=0;i<w+1;i++)
        c[i] = -1;
    char a[h+1][w+1];
    char st;
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
            cin >> a[i][j];
    }
    for(i=0;i<h;i++)
    {
        no = 1;
        st = a[i][0];
        if(st == '.')
        {
            for(j=1;j<w;j++)
            {
                if(a[i][j] != st)
                    break;
            }
            if(j == w)
            {
                r[tmp] = i;
                tmp++;
            }
        }
    }
    tmp = 0;
    for(i=0;i<w;i++)
    {
        no = 1;
        st = a[0][i];
        if(st == '.')
        {
            for(j=1;j<h;j++)
            {
                if(a[j][i] != st)
                    break;
            }
            if(j == h)
            {
                c[tmp] = i;
                tmp++;
            }
        }
    }
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            p = 1;
            tr = 0;
            tc = 0;
            while(r[tr] != -1)
            {
                if(r[tr] == i)
                {
                    p = 0;
                    break;
                }
                tr++;
            }
            while(c[tc] != -1)
            {
                if(c[tc] == j)
                {
                    p = 0;
                    break;
                }
                tc++;
            }
            if(p == 1)
                cout << a[i][j];
        }
        tr = 0;
        p = 1;
        while(r[tr] != -1)
        {
            if(r[tr] == i)
            {
                p=0;
                break;
            }
            tr++;
        }
        if(p == 1)
        cout << endl;
    }
}
