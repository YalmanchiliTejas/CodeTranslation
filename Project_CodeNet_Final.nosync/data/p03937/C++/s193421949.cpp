//In the Name of God
//Ya Ali

#include<bits/stdc++.h>

#define err(A) cout<<#A<<" = "<<(A)<<endl

using namespace std;

const int maxn=10;

int n,m;

string s[maxn];

bool vis[maxn][maxn];

void dfs(int x,int y)
{
  vis[x][y]=true;
  if(x+1<n and s[x+1][y]=='#')
    dfs(x+1,y);
  else if(y+1<m and s[x][y+1]=='#')
    dfs(x,y+1);
}
  
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>n>>m;

  for(int i=0;i<n;i++)
    cin>>s[i];

  if(s[0][0]=='#')
    dfs(0,0);

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(vis[i][j]!=(s[i][j]=='#'))
	{
	  cout<<"Impossible"<<endl;
	  return  0;
	}
  cout<<"Possible"<<endl;
  
  return 0;
}
