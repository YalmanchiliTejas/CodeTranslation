#include<iostream>
#include<vector>

using namespace std;

int n,m;
int ans;

vector<bool> done;
vector<vector<int>> to;

void dfs(int id)
{
  bool flag=true;
  for(int i=0;i<n;i++)
    if(done[i]==false)
      flag=false;
  if(flag)
  {
    ans++;
    return;
  }
  for(int i=0;i<to[id].size();i++)
  {
    int nxid=to[id][i];
    if(done[nxid]==true)continue;
    done[nxid]=true;
    dfs(nxid);
    done[nxid]=false;
  }
  return;
}


int main()
{
  cin>>n>>m;
  to=vector<vector<int>>(n);
  done=vector<bool>(n,false);
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  
  ans=0;
  
  done[0]=true;
  dfs(0);
  
  cout<<ans<<endl;
}