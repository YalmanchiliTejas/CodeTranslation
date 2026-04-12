#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#define ll long long
#define INF 1000000000
#define mod 1000000007
#define rep(i,n) for(int i=0;i<int(n);i++)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool debug=false;

vector<int>g[10];
int n,m;
int sum;
bool used[10];

void dfs(int now,int cnt){
  if(cnt==n){sum++;return ;};
  used[now]=true;
  rep(i,g[now].size()){
    if(!used[g[now][i]])dfs(g[now][i],cnt+1);
  }
  used[now]=0;
}

int main(){
  int a,b;
  cin>>n>>m;
  rep(i,m){
    cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(1,1);
  cout<<sum<<endl;
}