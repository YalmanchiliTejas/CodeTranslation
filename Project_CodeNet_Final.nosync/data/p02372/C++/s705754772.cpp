#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<queue>
#define Vmaxn 100010
#define Emaxn 500010
using namespace std;

struct Node
{
    int x,y,val,pre;
};
int g_[Vmaxn];
Node g[Emaxn];

int n,Dmax=0;
int h[Vmaxn],w[Vmaxn],s[Vmaxn],e[Vmaxn];

void dfs(int s,int u){
    h[u]=1;w[u]=s;
    int j=g_[u];
    while(j!=-1)
    {
        int v=g[j].y;
        if(h[v]==0){
            dfs(s+g[j].val,v);
        }
        j=g[j].pre;
    }
}

int main()
{
    int i;

    cin>>n;
    memset(g_,-1,sizeof g_);
    for(i=0;i<2*(n-1);i++)
    {
        cin>>g[i].x>>g[i].y>>g[i].val;
        g[i].pre=g_[g[i].x];
        g_[g[i].x]=i;

        g[i+1].x=g[i].y;g[i+1].y=g[i].x;g[i+1].val=g[i].val;
        g[i+1].pre=g_[g[i+1].x];
        g_[g[i+1].x]=i+1;
        i++;
    }


    memset(h,0,sizeof h);
    memset(w,0,sizeof w);
    dfs(0,0);
    int start=0;
    for(i=0;i<n;i++)
        if(w[i]>Dmax){
            Dmax=w[i];
            start=i;
    }

    Dmax=0;
    int end=0;
    memset(h,0,sizeof h);
    memset(w,0,sizeof w);
    dfs(0,start);
    for(i=0;i<n;i++)
        if(w[i]>Dmax){
            Dmax=w[i];
            end=i;
    }
    for(i=0;i<n;i++)
        s[i]=w[i];


    Dmax=0;
    memset(h,0,sizeof h);
    memset(w,0,sizeof w);
    dfs(0,end);
    for(i=0;i<n;i++)
        e[i]=w[i];

    for(i=0;i<n;i++)
        cout<<max(s[i],e[i])<<endl;
    return 0;
}

