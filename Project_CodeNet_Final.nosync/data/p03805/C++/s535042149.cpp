
#include<iostream>
//#include<bits/stdc++.h>
#include<cmath>
#include<string>
#include<cstdio>
#include<cstring>
#include<queue>
#define pq priority_queue
#define Pi acos(-1.0)
using namespace std;
#define MOD 1000000007
int n;
int ans=0;
bool life[10];
vector <int> v[10];
int dfs(int x,int pre)
{
    if(x==n)
        ans++;
    for(int i=0;i<v[pre].size();i++)
    {
        if(!life[v[pre][i]])
        {
            life[v[pre][i]]=1;
            dfs(x+1,v[pre][i]);
            life[v[pre][i]]=0;
        }
    }
}
int main()
{
    int m,a,b;
    cin>>n>>m;
    while(m--)
    {
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    life[1]=1;
    dfs(1,1);
    printf("%d",ans);
    return 0;
}
