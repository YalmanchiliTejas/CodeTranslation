#include<iostream>
#include<string>
#include <bits/stdc++.h>

using namespace std;

char a[60][60];
int b[60],c[60][30],d[30];

int main()
{
    int n,i,j;
    cin >> n;
    for(i=0;i<n;i++)
    {
        scanf(" %s",a[i]);
        b[i]=strlen(a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<b[i];j++)
        {
            c[i][a[i][j]-'a']++;
        }
        for(j=0;j<26;j++)
        {
            if(i==0) d[j]=c[i][j];
            else d[j]=min(d[j],c[i][j]);
        }
    }
    for(i=0;i<26;i++)
    {
        for(j=0;j<d[i];j++)
        {
            printf("%c",i+'a');
        }
    }
    printf("\n");
    return 0;
}