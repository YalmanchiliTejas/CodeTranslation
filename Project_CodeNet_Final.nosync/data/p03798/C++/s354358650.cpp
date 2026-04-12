#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#define maxn 100000
#define inf  1000000000000000000
using namespace std;
char s[200010];
char ans[200010];

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++)
    {
        scanf("%c",&s[i]);
    }
    int flag=0;
    ans[1]='S';
    ans[2]='S';
    for(int i=2;i<=n;i++)
    {
     if((ans[i]=='S'&&s[i]=='o')||(ans[i]=='W'&&s[i]=='x'))
     {
         ans[i+1]=ans[i-1];
     }
        if((ans[i]=='S'&&s[i]=='x')||(ans[i]=='W'&&s[i]=='o'))
        {
            if(ans[i-1]=='S')
                ans[i+1]='W';
            else if(ans[i-1]=='W')
                ans[i+1]='S';
        }
        if(i==n)
        {
            if(ans[n+1]==ans[1])
            {
                
                if((ans[1]=='S'&&s[1]=='x')||(ans[1]=='W'&&s[1]=='o'))
                {
                    if(ans[n]!=ans[2])
                        flag=1;
                }
                if((ans[1]=='S'&&s[1]=='o')||(ans[1]=='W'&&s[1]=='x'))
                {
                    if(ans[n]==ans[2])
                        flag=1;
                }
            }
        }
    }
    if(flag)
    {
        for(int i=1;i<=n;i++)
            printf("%c",ans[i]);
        return 0;
    }
    ans[1]='S';
    ans[2]='W';
    for(int i=2;i<=n;i++)
    {
        if((ans[i]=='S'&&s[i]=='o')||(ans[i]=='W'&&s[i]=='x'))
        {
            ans[i+1]=ans[i-1];
        }
        if((ans[i]=='S'&&s[i]=='x')||(ans[i]=='W'&&s[i]=='o'))
        {
            if(ans[i-1]=='S')
                ans[i+1]='W';
            else
                ans[i+1]='S';
        }
        if(i==n)
        {
            if(ans[n+1]==ans[1])
            {
                
                if((ans[1]=='S'&&s[1]=='x')||(ans[1]=='W'&&s[1]=='o'))
                {
                    if(ans[n]!=ans[2])
                        flag=1;
                }
                if((ans[1]=='S'&&s[1]=='o')||(ans[1]=='W'&&s[1]=='x'))
                {
                    if(ans[n]==ans[2])
                        flag=1;
                }
            }
        }
    }
    if(flag)
    {
        for(int i=1;i<=n;i++)
            printf("%c",ans[i]);
        return 0;
    }
    ans[1]='W';
    ans[2]='S';
    for(int i=2;i<=n;i++)
    {
        if((ans[i]=='S'&&s[i]=='o')||(ans[i]=='W'&&s[i]=='x'))
        {
            ans[i+1]=ans[i-1];
        }
        if((ans[i]=='S'&&s[i]=='x')||(ans[i]=='W'&&s[i]=='o'))
        {
            if(ans[i-1]=='S')
                ans[i+1]='W';
            else
                ans[i+1]='S';
        }
        if(i==n)
        {
            if(ans[n+1]==ans[1])
            {
            
                if((ans[1]=='S'&&s[1]=='x')||(ans[1]=='W'&&s[1]=='o'))
                {
                    if(ans[n]!=ans[2])
                            flag=1;
                }
                if((ans[1]=='S'&&s[1]=='o')||(ans[1]=='W'&&s[1]=='x'))
                {
                    if(ans[n]==ans[2])
                            flag=1;
                }
            }
        }
    }
    if(flag)
    {
        for(int i=1;i<=n;i++)
            printf("%c",ans[i]);
        return 0;
    }
    ans[1]='W';
    ans[2]='W';
    for(int i=2;i<=n;i++)
    {
        if((ans[i]=='S'&&s[i]=='o')||(ans[i]=='W'&&s[i]=='x'))
        {
            ans[i+1]=ans[i-1];
        }
        if((ans[i]=='S'&&s[i]=='x')||(ans[i]=='W'&&s[i]=='o'))
        {
            if(ans[i-1]=='S')
                ans[i+1]='W';
            else
                ans[i+1]='S';
        }
        if(i==n)
        {
            if(ans[n+1]==ans[1])
            {
                
                if((ans[1]=='S'&&s[1]=='x')||(ans[1]=='W'&&s[1]=='o'))
                {
                    if(ans[n]!=ans[2])
                        flag=1;
                }
                if((ans[1]=='S'&&s[1]=='o')||(ans[1]=='W'&&s[1]=='x'))
                {
                    if(ans[n]==ans[2])
                        flag=1;
                }
            }
        }
    }
    if(flag)
    {
        for(int i=1;i<=n;i++)
        printf("%c",ans[i]);
        return 0;
    }
    printf("-1\n");
    return 0;
}
