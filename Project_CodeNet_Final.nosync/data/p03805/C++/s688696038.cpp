#include <bits/stdc++.h>
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
typedef long long ll;
using namespace std;

int n,m,ans;
int a[10],b[10];
string color[10];

vector<int> adj[10];

bool ch(){
  bool flag = true;
  for(int i=0;i<n;i++){
    if(color[i] == "White")
    flag = false;
  }
  if(flag){
    return true;
  }else{
    return false;
  }
}

void ini(){
  rep(i,n)color[i]="White";
}

void dfs(int now){

  if(ch()){
    ans++;
    return;
  }
  for(int i : adj[now]){
    if(color[i]=="White"){
      color[i]="Black";
      dfs(i);
      color[i]="White";
    }
  }

}
int main(){
  cin>>n>>m;
  rep(i,n)color[i]="White";

  int x,y;
  rep(i,m){
    cin>>x>>y;
    x--;y--;
    adj[x].push_back(y);
    adj[y].push_back(x);

  }
  int now=0;
  color[now]="Black";
  dfs(now);
  cout<<ans<<endl;
}
