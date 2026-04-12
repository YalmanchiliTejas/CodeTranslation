#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = long long unsigned;
using P = pair<int,int>;
const int INF=1001001;
const int NMAX=8;
vector<vector<int>> a(NMAX);
int ans;
int dfs(int node,int n, bool visit[NMAX]){

  bool all_visit=true;
  int ans=0;
  rep(i,n){
    if (visit[i]==false)all_visit=false;
  }
  if (all_visit) return 1;

  for (int to:a[node]){
    if (visit[to]==true)continue;
  //  cout<<to<<"to"<<node<<"node"<<endl;
    visit[to]=true;
    ans+=dfs(to,n,visit);
    visit[to]=false;


  }
return ans;
cout<<ans<<endl;
  }

int main(){
  int n,m;
  cin>>n>>m;
  rep(i,m){
    int a1,b1;
    cin>>a1>>b1;

    a1--;b1--;
    a[a1].push_back(b1);
    a[b1].push_back(a1);

  }
  bool visit[NMAX];
  rep(i,NMAX)visit[i]=false;
  visit[0]=true;
  cout<<dfs(0,n,visit);

}
