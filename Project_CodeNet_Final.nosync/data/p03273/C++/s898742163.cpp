#include<bits/stdc++.h>

using namespace std;
char a[111][111];
void removeCol(int x,int n,int m)
{
    for (int i=x;i<m-1;i++)
    {
        for (int j=0;j<n;j++)
        {
            a[j][i]=a[j][i+1];
        }
    }
    return ;
}
void removeRow(int x,int n,int m)
{
    for (int i=x;i<n-1;i++)
    {
        for (int j=0;j<m;j++)
        {
            a[i][j]=a[i+1][j];
        }
    }
    return ;
}
int main()
{
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;i++)
    {     
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }  
    }
    for (int i=0;i<n;)
    {
        bool flg=1;
        for (int j=0;j<m&&flg;j++)
        {
            if (a[i][j]=='#') flg=0;
        }
        if (flg) removeRow(i,n,m),--n;
        else ++i;
    }
    for (int i=0;i<m;)
    {
        bool flg=1;
        for (int j=0;j<n&&flg;j++)
        {
            if (a[j][i]=='#') flg=0;
        }
        if (flg) removeCol(i,n,m),--m;
        else ++i;
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}