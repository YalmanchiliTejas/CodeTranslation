#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int a[55][30],b[30];
int main()
{
    int n,f=0;
    scanf("%d",&n);
    char s[55];
    for(int i=0;i<30;i++) b[i]=55;
    for(int i=0;i<55;i++)
        for(int j=0;j<30;j++)
        a[i][j]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        int len=strlen(s);
        for(int j=0;j<len;j++)
            a[i][s[j]-97]++;
    }
    for(int i=0;i<26;i++)
        for(int j=0;j<n;j++)
        if(a[j][i]<b[i])
            b[i]=a[j][i];
    for(int i=0;i<26;i++)
        for(int j=0;j<b[i];j++)
        {
            printf("%c",i+97);
            f=1;
        }
     if(f) printf("\n");
    return 0;
}
