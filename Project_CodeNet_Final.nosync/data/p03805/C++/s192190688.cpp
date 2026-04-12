#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define llmax LLONG_MAX   //ranges are defined in climits
#define llmin LLONG_MIN
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
int n,paths=0,ans=0;
void dfsRec(vector<int>adj[],int s, bool visited[])
{
  int count=0;
  for(int i=0;i<n;i++)
  {
    if(visited[i])  ++count;
  }
  if(count==n)  {++ans;return;}
  for(int u:adj[s])
  {
    if(!visited[u])
    {
      visited[u]=true;
      dfsRec(adj,u,visited);
      visited[u]=false;
    }
  }
  
}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int m;cin>>n>>m;
  vector<int>adj[n];
  for(int j=0;j<m;j++)
  {
    int a,b;cin>>a>>b;
    adj[--a].pb(--b);
    adj[b].pb(a);
  }
  bool visited[n];
  for(int i=0;i<n;i++)  visited[i]=false;
  visited[0]=true;
  dfsRec(adj,0,visited);
  cout<<ans;
	return 0;
}
