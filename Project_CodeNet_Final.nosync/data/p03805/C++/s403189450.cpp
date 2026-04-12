#include<bits/stdc++.h>
using namespace std;
int used[10];
int d[10];
int G[10][10];
int n,ans;

int ch(){
  for(int i=1;i<n;i++){
    if(G[d[i-1]][d[i]])continue;
    return 0;
  }
  return 1;
}

void rec(int x){
  if(x==n){
    if(ch())ans++;
    return;
  }
  for(int i=1;i<n;i++){
    if(used[i])continue;
    used[i]=1;
    d[x]=i;
    rec(x+1);
    used[i]=0;
  }
}

int main(){
  int m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    G[a][b]=G[b][a]=1;
  }
  used[0]=1;
  rec(1);
  cout<<ans<<endl;
  return 0;
}
