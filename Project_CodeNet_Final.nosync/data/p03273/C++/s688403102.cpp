#include<iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int r, c, i, j, k, f;
    char p[101][101];
    cin >> r >> c;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            cin >> p[i][j];
    }

    for(i=0; i<r; i++)
    {
        f=1;
        for(j=0; j<c; j++)
        {
            if(p[i][j]!='.')
                f=0;
        }
        if(f==1)
        for(j=0; j<c; j++)
            p[i][j]='0';
    }

    for(i=0; i<c; i++)
    {
        f=1;
        for(j=0; j<r; j++)
        {
            if(p[j][i]!='.' && p[j][i]!='0')
                f=0;
        }
        if(f==1)
        for(j=0; j<r; j++)
            p[j][i]='0';
    }
    for(i=0; i<r; i++)
    {
        f=1;
        for(j=0; j<c; j++)
        {
           if(p[i][j]!='0')
            {

                cout << p[i][j];
               f=0;
            }
        }
        if(f==0)
            cout << "\n";
    }


}
