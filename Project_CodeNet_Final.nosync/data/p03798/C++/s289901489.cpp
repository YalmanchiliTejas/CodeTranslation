#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char a[100100],b[100100];

int main()
{
    int n,i,j=0,flag=0;
    cin >> n;
    scanf(" %s",a);
    a[n]=a[0];a[n+1]=a[1];
    while(!flag&&j<4)
    {
        if(j==0)
        {
            b[0]='S';
            b[1]='S';
        }
        else if(j==1)
        {
            b[0]='S';
            b[1]='W';
        }
        else if(j==2)
        {
            b[0]='W';
            b[1]='S';
        }
        else if(j==3)
        {
            b[0]='W';
            b[1]='W';
        }
        for(i=1; i<=n; i++)
        {
            if(b[i]=='S'&&a[i]=='o')
                b[i+1]=b[i-1];
            else if (b[i]=='S'&&a[i]=='x')
            {
                if(b[i-1]=='S') b[i+1]='W';
                else if(b[i-1]=='W') b[i+1]='S';
            }
            else if (b[i]=='W'&&a[i]=='o')
            {
                if(b[i-1]=='S') b[i+1]='W';
                else if(b[i-1]=='W') b[i+1]='S';
            }
            else if (b[i]=='W'&&a[i]=='x')
                b[i+1]=b[i-1];
        }
        if(b[n]==b[0]&&b[n+1]==b[1]) flag=1;
        j++;
    }
    if(flag==0)
    cout << "-1" << endl;
    else
    {
        for(i=0;i<n;i++)
        {
            cout << b[i];
        }
    }
    return 0;
}