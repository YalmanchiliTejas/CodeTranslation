#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <string.h>
#include <map>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#define INF 1000000
#define MAX 500000
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vector <vi> adj(MAX);
vi col;
 ll n;
 vi dfs_num,dfs_parent,dfs_low,vertex;
int dfsnumcnt=0,dfsRoot,rootChildren=0;
void apoint(int u)
{
  dfs_num[u]=dfs_low[u]=dfsnumcnt++;
  for(ll i=0;i<adj[u].size();i++)
  {
    ll v=adj[u][i];
    if(dfs_num[v]==INF)
    {
      dfs_parent[v]=u;
      if(u==dfsRoot) rootChildren++;
      apoint(v);
      if(dfs_low[v]>=dfs_num[u])
        vertex[u]=1;
      dfs_low[u]=min(dfs_low[u],dfs_low[v]);
    }
    else if(v!=dfs_parent[u])
    dfs_low[u]=min(dfs_low[u],dfs_num[v]);
 }
}
int main()
{
  // freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ll n;
cin>>n;
ll ans=n*800-(n/15)*200;
cout<<ans<<endl;
return 0;
}