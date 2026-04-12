#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int N = 1e5+10;
typedef long long LL;
const LL mod = 1e9+7;
char str[N], s1[N];
int judge(int n)
{
    for(int i=1; i<n-1; i++)
    {
        if(s1[i]=='S')
        {
            if(str[i]=='o') s1[i+1]=s1[i-1];
            else
            {
                if(s1[i-1]=='S') s1[i+1]='W';
                else s1[i+1]='S';
            }
        }
        else
        {
            if(str[i]=='x') s1[i+1]=s1[i-1];
            else
            {
                if(s1[i-1]=='S') s1[i+1]='W';
                else s1[i+1]='S';
            }
        }
    }
    int flag=0;
    if(s1[n-1]=='S')
    {
        if(str[n-1]=='o')
        {
            if(s1[n-2]==s1[0])
            {
                if(s1[0]=='S')
                {
                    if(str[0]=='o'&&s1[1]==s1[n-1]) flag=1;
                    if(str[0]=='x'&&s1[1]!=s1[n-1]) flag=1;
                }
                if(s1[0]=='W')
                {
                    if(str[0]=='o'&&s1[1]!=s1[n-1]) flag=1;
                    if(str[0]=='x'&&s1[1]==s1[n-1]) flag=1;
                }
            }
        }
        else
        {
            if(s1[n-2]!=s1[0])
            {
                if(s1[0]=='S')
                {
                    if(str[0]=='o'&&s1[1]==s1[n-1]) flag=1;
                    if(str[0]=='x'&&s1[1]!=s1[n-1]) flag=1;
                }
                if(s1[0]=='W')
                {
                    if(str[0]=='o'&&s1[1]!=s1[n-1]) flag=1;
                    if(str[0]=='x'&&s1[1]==s1[n-1]) flag=1;
                }
            }
        }
    }
    else
    {
        if(str[n-1]=='o')
        {
            if(s1[n-2]!=s1[0])
            {
                if(s1[0]=='S')
                {
                    if(str[0]=='o'&&s1[1]==s1[n-1]) flag=1;
                    if(str[0]=='x'&&s1[1]!=s1[n-1]) flag=1;
                }
                if(s1[0]=='W')
                {
                    if(str[0]=='o'&&s1[1]!=s1[n-1]) flag=1;
                    if(str[0]=='x'&&s1[1]==s1[n-1]) flag=1;
                }
            }
        }
        else
        {
            if(s1[n-2]==s1[0])
            {
                if(s1[0]=='S')
                {
                    if(str[0]=='o'&&s1[1]==s1[n-1]) flag=1;
                    if(str[0]=='x'&&s1[1]!=s1[n-1]) flag=1;
                }
                if(s1[0]=='W')
                {
                    if(str[0]=='o'&&s1[1]!=s1[n-1]) flag=1;
                    if(str[0]=='x'&&s1[1]==s1[n-1]) flag=1;
                }
            }
        }
    }
    if(flag==1)
    {
        s1[n]='\0';
        return 1;
    }
    return 0;
}

int main()
{

    int n;
    scanf("%d", &n);
    scanf("%s",str);
    s1[0]='S',s1[1]='S';
    int x=judge(n);
    if(x==1)
    {
        cout<<s1<<endl;
        return 0;
    }
    s1[0]='W', s1[1]='W';
    x=judge(n);
    if(x==1)
    {
        cout<<s1<<endl;
        return 0;
    }
    s1[0]='S',s1[1]='W';
    x=judge(n);
    if(x==1)
    {
        cout<<s1<<endl;
        return 0;
    }
    s1[0]='W',s1[1]='S';
    x=judge(n);
    if(x==1)
    {
        cout<<s1<<endl;
        return 0;
    }
    cout<<-1<<endl;
    return 0;

}







