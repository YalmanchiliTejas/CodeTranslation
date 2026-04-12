#include<bits/stdc++.h>
using namespace std;

int main(){
  while(1){
  int n,m;
  int ans=0;
  int a;
  priority_queue<int> q;
  cin>>n>>m;
  if(n+m==0) break;
  for(int i=1;i<=n;i++){cin>>a;q.push(a);}
  for(int i=1;i<=m;i++){cin>>a;q.push(a);}
  int af;
  af=q.top();q.pop();
    while(!q.empty()){
    int be=q.top();
    q.pop();
    ans=max(ans,af-be);
    af=be;
  }
  ans=max(af,ans);
  cout<<ans<<endl;
  }
  return 0;
}