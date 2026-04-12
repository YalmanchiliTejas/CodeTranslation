#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 300000+50
#define maxm 30000
#define ll long long
#define mod 1000000000+7
#define mian main
#define mem(a,b) memset(a,b,sizeof a)
#ifndef ONLINE_JUDGE
   #define dbg(x) cout<<#x<<"="<<x<<endl;
#else 
   #define dbg(x) 
#endif
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=10*x+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline void Out(int a) 
{
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}
int main()
{
    int n,m;
    n=read();m=read();
    char s[105][105];
    for(int i=0;i<n;++i) scanf("%s",s[i]);
    bool x[105],y[105];
    mem(x,0);mem(y,0);
    for(int i=0;i<n;++i)
    {
        if(s[i][0]=='.'){
        int flag=1;
        for(int j=1;j<m;++j)
        {
            if(s[i][j]!=s[i][0]) {flag=0;break;}
        }
        if(flag) x[i]=1;
        }
    }
    for(int i=0;i<m;++i)
    {
        if(s[0][i]=='.'){
        int flag=1;
        for(int j=1;j<n;++j)
        {
            if(s[j][i]!=s[0][i]) {flag=0;break;}
        }
        if(flag) y[i]=1;
        }
    }
   // for(int i=0;i<m;++i) dbg(y[i]);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(!x[i]&&!y[j]) cout<<s[i][j];
        }
       if(!x[i]) cout<<endl;
    }
}