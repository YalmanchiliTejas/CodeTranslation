#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
vector<vector<int> >vvi(10);
int n,m;
int ans=0;
void dfs(int now,int bit,int depth){
  if(depth==n){
    ans++;
    return;
  }
  for(int i=0;i<vvi[now].size();i++){
    if((bit&(1<<vvi[now][i]))==0){
      dfs(vvi[now][i],bit+(1<<vvi[now][i]),depth+1);
    }
  }
}
int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    vvi[a].pb(b);
    vvi[b].pb(a);
  }
  dfs(1,2,1);
  cout<<ans<<endl;
  return 0;
}
