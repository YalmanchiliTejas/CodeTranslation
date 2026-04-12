#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int> v[n+1];
  for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  if(n%2){
    cout<<"First"<<endl;
    return 0;
  }
  queue<int> q;
  bool used[n+1];
  fill(used,used+n+1,false);
  int d[n+1];
  int cnt[n+1];
  fill(cnt,cnt+n+1,0);
  int ko[n+1];
  fill(ko,ko+n+1,0);
  for(int i=1;i<=n;i++){
    if(v[i].size()==1){
      q.push(i);
      used[i]=true;
      d[i]=0;
    }
    cnt[i]=v[i].size();
  }
  while(q.size()>0){
    int now=q.front();
    q.pop();
    for(int i=0;i<v[now].size();i++){
      int ne=v[now][i];
      
      if(used[ne])continue;
      cnt[ne]--;
      if(d[now]==0)ko[ne]++;
      if(ko[ne]>=2){
        cout<<"First"<<endl;
        return 0;
      }
      if(cnt[ne]==1){
        used[ne]=true;
        q.push(ne);
        if(ko[ne]==1)d[ne]=1;
        else d[ne]=0;
      }
    }
  }
  cout<<"Second"<<endl;
}
      
      
