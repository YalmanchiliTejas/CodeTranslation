#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int maxn=300005;
char s[maxn];
char a[maxn];
int n;
char change(char a)
{
    if(a=='S') return 'W';
    if(a=='W') return 'S';
}
int dfs()
{
    for(int x=2;x<n;x++)
    {
        if(s[x]=='o')
        {
            if(a[x]=='S')
            {
                a[x+1]=a[x-1];
            }
            else
            {
                a[x+1]=change(a[x-1]);
            }
        }
        else
        {
            if(a[x]=='W')
            {
                a[x+1]=a[x-1];
            }
            else
            {
                a[x+1]=change(a[x-1]);
            }
        }
    }
    int flag1=0,flag2=0;
    if(a[1]=='S')
    {
        if(s[1]=='o'&&a[2]==a[n]) flag1=1;
        else if(s[1]=='x'&&a[2]==change(a[n])) flag1=1;
    }
    else
    {
        if(s[1]=='o'&&a[2]!=a[n]) flag1=1;
        else if(s[1]=='x'&&a[2]!=change(a[n])) flag1=1;
    }
    if(a[n]=='S')
    {
        if(s[n]=='o'&&a[1]==a[n-1]) flag2=1;
        else if(s[n]=='x'&&a[1]==change(a[n-1])) flag2=1;
    }
    else
    {
        if(s[n]=='o'&&a[1]==change(a[n-1])) flag2=1;
        else if(s[n]=='x'&&a[1]==a[n-1]) flag2=1;
    }
    if(flag1&&flag2) return 1;
    return 0;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    a[1]='S';a[2]='S';
    if(dfs())
    {
        printf("%s\n",a+1);
        return 0;
    }
    a[1]='S';a[2]='W';
    if(dfs())
    {
        printf("%s\n",a+1);
        return 0;
    }
    a[2]='S';a[1]='W';//WS
    if(dfs())
    {
        printf("%s\n",a+1);
        return 0;
    }
    a[1]='W';a[2]='W';//WW
    if(dfs())
    {
        printf("%s\n",a+1);
        return 0;
    }
    printf("-1\n");
    return 0;
}