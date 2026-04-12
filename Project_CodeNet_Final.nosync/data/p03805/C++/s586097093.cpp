#include<bits/stdc++.h>
using namespace std;
int n,m,p=0;
 vector<int>v[10];

void dfssecond(bool vis[],int s)
{
  /*cout<<"s  "<<s<<endl;
for(int i=1;i<=n;i++)
{
  cout<<vis[i]<<" ";
}
cout<<endl<<endl;*/
vis[s]=1;
for(int i=0;i<v[s].size();i++)
{
  if(!vis[v[s][i]])
  {
    dfssecond(vis,v[s][i]);
    //cout<<"t "<<s<<endl;
   /* for(int i=1;i<=n;i++)
{
  cout<<vis[i]<<" ";
}
cout<<endl;*/
  }
}
for(int i=1;i<=n;i++)
{
  if(!vis[i])
  {
    
    vis[s]=0;
  }
  
}
if(vis[s]!=0)
{
p++;
//cout<<"p "<<p<<"  "<<"s "<<s<<endl;
vis[s]=0;
}
//return;
}

/*int  dfs(bool visited[],int s)
{int count=0;
    visited[s]=1;
    for(int i=0;i<v[s].size();i++)
    {
         if(!visited[v[s][i]])
         {
          if( !(dfssecond(visited,v[s][i],count)))
          {
              //count++; 
          }
         }
    }
    return count;
}*/








void firstdfs()
{
  
  int count=0;
     bool visited[n+1];
     memset(visited,0,sizeof(visited));
     visited[1]=1;
     dfssecond(visited,1);
     cout<<p<<endl;
  
}
int main()
{
  //int n,m;
  cin>>n>>m;
  //vector<int>v[n+1];
  for(int i=1;i<=m;i++)
  {
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);

  }
  //cout<<endl<<endl;
firstdfs();
}