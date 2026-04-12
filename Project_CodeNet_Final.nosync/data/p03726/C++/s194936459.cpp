/**
 Input:
 3
 1 2
 2 3
**/
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <bits/stdc++.h>
#define fw(x) freopen("x.txt","w",stdout)
#define For(i,a,b,c) for(int i = a;i < b;i+=c)
#define REP(i,n) for(int i = 0;i < n;++i)
#define mem(a,s) memset(a,s,sizeof a)
#define fast ios_base::sync_with_stdio(0)
#define pf printf
#define sc scanf
#define ll long long
#define N 100000+10
using namespace std;

 vector<int>adj[N];
 int mark[N];
 int n;

 void dfs(int x,int col)
 {
  // cout<<"HI\n";
   for(int i=0;i<adj[x].size();i++)
   {
     //cout<<"HI\n";
     if(col!=adj[x][i])
      dfs(adj[x][i],x);
    else
    continue;
   }
   if(!mark[x] && !mark[col])
    {
      mark[x]=1;
      mark[col]=1;
    }
 }
int main()
{
   // freopen("in11.txt","r",stdin);
   cin>>n;
   for(int i=1;i<n;i++)
   {
     int u,v;
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
   }
   mark[0]=1;
   dfs(1,0);
   int flag=1;

   for(int i=0;i<=n;i++)
    if(mark[i]==0)
      flag=0;
    if(!flag)
      puts("First");
    else
      puts("Second");
  return 0;
}
