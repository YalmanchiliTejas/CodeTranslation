#include<iostream>
using namespace std;
char a[110][110];
char b[110][110];
int main()
{
    int n,m,i,j,k,x,t;
    cin >> n >> m;
    k=0;
    for(i=0;i<n;i++)
    {
        t=0;
        for(j=0;j<m;j++)
        {
            cin >> a[k][j];
            if(a[k][j]=='#')
                t=1;
        }
        if(t)
            k++;
    }
    x=0;
    for(i=0;i<m;i++)
    {
        t=0;
        for(j=0;j<k;j++)
        {
            b[j][x]=a[j][i];
            if(a[j][i]=='#')
                t=1;
        }
        if(t)
            x++;
    }
    for(i=0;i<k;i++)
    {
        for(j=0;j<x;j++)
            cout << b[i][j];
        cout << endl;
    }
    return 0;
}
