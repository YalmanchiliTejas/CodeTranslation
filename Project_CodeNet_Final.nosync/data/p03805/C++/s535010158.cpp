#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define MAX 100005
#define int long long
using namespace std;
const int MOD=1000000007;
const int INF=1000000009;

vector<vector<int>> tree;
int n,m,sum=0;

int dfs(int s,vector<int> used){
  bool flag=true;
  rep(i,n)if(used[i]==0)flag=false;
  if(flag)sum++;
  rep(i,tree[s].size()){
    int u=tree[s][i];
    if(used[u]==1)continue;
    used[u]=1;
    dfs(u,used);
    used[u]=0;
  }
  return sum;
}

signed main(){
  cin>>n>>m;
  tree=vector<vector<int>>(n);
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    tree[a].pb(b);
    tree[b].pb(a);
  }
  vector<int> used(n);
  used[0]=1;
  cout<<dfs(0,used)<<endl;


  return 0;
}
