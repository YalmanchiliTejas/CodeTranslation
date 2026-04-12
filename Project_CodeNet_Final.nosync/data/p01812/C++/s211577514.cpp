#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n,m,k;cin>>n>>m>>k;
  vector<int> d(m);
  vector<vector<int>> v(n,vector<int>(k));
  int i,j,l;
  rep(i,m)cin>>d[i];
  rep(i,n)rep(j,k)cin>>v[i][j];
  vector<vector<int>> v0(m,vector<int>(k));
  rep(i,m)v0[i]=v[d[i]-1];
  rep(i,m)rep(j,k)
  {
    rep(l,m)
    {
      if(v0[i][j]==d[l])
      {
        v0[i][j]=l;
        break;
      }
      if(l==m-1)v0[i][j]=-1;
    }
  }
  vector<vector<int>> move(1<<m,vector<int>(k,0));
  rep(i,1<<m)
  {
    if(i==0)continue;
    rep(j,k)
    {
      vector<bool> exist(m,false);
      for(l=m-1;l>=0;l--)
      {
        if(i&(1<<l)&&v0[m-1-l][j]!=-1)
        {
          exist[v0[m-1-l][j]]=true;
        }
      }
      rep(l,m)
      {
        move[i][j]*=2;
        if(exist[l])move[i][j]+=1;
      }
    }
  }
  queue<int> q;
  queue<int> q2;
  vector<bool> visited(1<<m,false);
  visited[(1<<m)-1]=true;
  q.push((1<<m)-1);
  int len=0;
  int ans;
  while(!q.empty())
  {
    while(!q.empty())
    {
      int now=q.front();
      q.pop();
      if(now==0)ans=len;
      rep(i,k)
      {
        if(!visited[move[now][i]])
        {
          q2.push(move[now][i]);
          visited[move[now][i]]=true;
        }
      }
    }
    while(!q2.empty())
    {
      q.push(q2.front());
      q2.pop();
    }
    len++;
  }
  cout<<ans<<endl;
}

