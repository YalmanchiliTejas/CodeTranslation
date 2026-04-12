#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
struct Grid{int x,y,t;};
struct Edge{int to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  const ll Inf = llINF;const int MAX_V=1010;vector<ll>d;
  Graph(int n):E(n){d.resize(MAX_V);E.resize(n);V=n;}
  void init(){for(int i=0;i<MAX_V;i++)d[i]=Inf;}
  void add_edge(int from,int to,int cost){E[from-1].pb({to-1,cost});}
};
ll n;
ll dp[3010][3010]={};
vector<ll>ho(3010);
ll dfs(int fr,int to,int now){
  if(fr==to){
    ///cout<<"!"<<endl;
    if(now==0)
      return dp[fr][to]=ho[to];
    else
      return dp[fr][to]=-ho[to];
  }
  if(dp[fr][to]!=-llINF)return dp[fr][to];
  // cout<<fr<<" "<<to<<" "<<now<<endl;
  if(now==0){
    return dp[fr][to]=max(dfs(fr+1,to,1)+ho[fr],dfs(fr,to-1,1)+ho[to]);
  }else{
    return dp[fr][to]=min(dfs(fr+1,to,0)-ho[fr],dfs(fr,to-1,0)-ho[to]);
  }
}
int main(){
  cin>>n;
  for(int i=0;i<n+1;i++)
    for(int j=0;j<n+1;j++)
      dp[i][j]=-llINF;
  for(int i=0;i<n;i++)cin>>ho[i];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    }
  }
  dfs(0,n-1,0);
  cout<<dp[0][n-1]<<endl;
  return 0;
}
