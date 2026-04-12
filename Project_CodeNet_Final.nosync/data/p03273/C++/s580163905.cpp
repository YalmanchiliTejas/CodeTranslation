#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-7;
const int N = 1e2+6, M = 1e4+5, OO = 0x3f3f3f3f;

int n,m,flag;
char a[N][N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            scanf(" %c", &a[i][j]);
        }
    }



    //ROOWWWWSSSS
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(a[i][j] == '#')flag = 1;
        }
        if(flag == 0)
        {
            for(int j = 0; j < m; ++j)
            {
                a[i][j] = '0';
            }
        }else
        {
            flag = 0;
        }
    }

    //ColumnSSSSSS
    for(int j = 0; j < m; ++j)
    {
        for(int i = 0; i < n; ++i)
        {
            if(a[i][j] == '#')flag = 1;
        }
        if(flag == 0)
        {
            for(int i = 0; i < n; ++i)
            {
                a[i][j] = '0';
            }
        }else
        {
            flag = 0;
        }
    }








    int x = 1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(a[i][j] == '0')
            {
                continue;
            }
            else
            {
                printf("%c", a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
