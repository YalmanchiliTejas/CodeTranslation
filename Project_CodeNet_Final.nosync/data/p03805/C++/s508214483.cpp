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

int g[10][10]={};


int dfs(int s,int N,vector<bool>used){
  bool flag=true;
  rep(i,N){
    if(used[i]==false){
      flag=false;
    }
  }
  if(flag)return 1;
  int sum=0;
  rep(i,N){
    if(g[s][i]==0)continue;
    if(used[i])continue;
    used[i]=true;
    sum+=dfs(i,N,used);
    used[i]=false;
  }
  return sum;
}


signed main(){
  int n,m;
  cin>>n>>m;
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    g[a][b]=1;
    g[b][a]=1;
  }
  vector<bool> used(n);
  used[0]=true;
  cout<<dfs(0,n,used)<<endl;

  return 0;
}
