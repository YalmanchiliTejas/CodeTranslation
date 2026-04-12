#include <iostream>
using namespace std;
int main () {
    int h,w,c1=0,c2=0,c=0;
    char a[110][110];
    cin >> h >> w;
    for (int i=1;i<=h;i++)
    {
        for (int j=1;j<=w;j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i=1;i<=h;i++)
    {
        for (int j=1;j<=w;j++)
        {
            if (a[i][j]=='.')
            {
                for (int k=1;k<=h;k++)
                {
                    if (a[k][j]=='#')
                    {
                        c1=1;
                    }
                }
                if (c1==0)
                {
                    for (int k=1;k<=h;k++)
                    {
                        a[k][j]='?';
                    }
                    c1=0;
                }
                c1=0;
                for (int k=1;k<=w;k++)
                {
                    if (a[i][k]=='#')
                    {
                        c2=1;
                    }
                }
                if (c2==0)
                {
                    for (int k=1;k<=w;k++)
                    {
                        a[i][k]='?';
                    }
                }
                c2=0;
            }
        }
    }
    for (int i=1;i<=h;i++)
    {
        for (int j=1;j<=w;j++)
        {
            if (a[i][j]!='?')
            {
                cout << a[i][j];
                c=1;
            }
        }
        if (c==1)
        {
            cout << endl;
        }
        c=0;
    }
    return 0;
}