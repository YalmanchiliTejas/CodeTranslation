#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char a[110][110];
int b[110],c[110],flag;

int main()
{
    int n,m,i,j;
    cin >> n >> m;
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < m; j ++)
        {
            cin >> a[i][j];
            if(a[i][j] != '.') flag = 1;
        }
        if(flag == 0) b[i] = 1;
        else flag = 0;
    }
    for(j = 0; j < m; j ++)
    {
        for(i = 0; i < n; i ++)
        {
            if(a[i][j] != '.') flag = 1;
        }
        if(flag == 0) c[j] = 1;
        else flag = 0;
    }
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < m; j ++)
        {
            if(b[i] || c[j]) continue;
            else printf("%c",a[i][j]);
        }
        if(!b[i]) printf("\n");
    }
    return 0;
}