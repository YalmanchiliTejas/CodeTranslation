#include <iostream>
using namespace std;
#include<string.h>
#include<set>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include <cstdio>
#include <cstdlib>
#include<stack>
#include<vector>
int a[110000];
struct lll
{
    int x,y,weizhi;
}sx[110000],sy[110000];
struct llll
{
    int x,y,cha;
}s1[110000*4];

int cmp1(lll x,lll y)
{
    return x.x<y.x;
}
int cmp2(lll x,lll y)
{
    return x.y<y.y;
}
int cmp3(llll x,llll y)
{
    return x.cha<y.cha;
}

int find(int n)
{
    if(n==a[n])
        return n;
    return find(a[n]);
}
int panduan(int n,int m)
{
    int n1=find(n);
    int m1=find(m);
    if(n1==m1)
        return 0;
    a[n1]=min(n1,m1);
    a[m1]=min(n1,m1);
    return 1;
}
int  main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
        cin>>sx[i].x>>sx[i].y;
        sx[i].weizhi=i;
        sy[i]=sx[i];
    }
    sort(sx+1,sx+1+n,cmp1);
    sort(sy+1,sy+n+1,cmp2);
    for(int i=1;i<n;i++)
    {
        s1[i].x=sx[i].weizhi;
        s1[i].y=sx[i+1].weizhi;
        s1[i].cha=sx[i+1].x-sx[i].x;
        s1[i+n-1].x=sy[i].weizhi;
        s1[i+n-1].y=sy[i+1].weizhi;
        s1[i+n-1].cha=sy[i+1].y-sy[i].y;
    }
    sort(s1+1,s1+1+2*n-2,cmp3);
    int sum=0;
    for(int i=1;i<=2*n-2;i++)
    {
        //cout<<s1[i].x<<"_"<<s1[i].y<<"_"<<s1[i].cha<<endl;
        if(panduan(s1[i].x,s1[i].y))
            sum+=s1[i].cha;
    }
    cout<<sum<<endl;
    return 0;
}
