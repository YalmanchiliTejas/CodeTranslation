#include<bits/stdc++.h>
using namespace std;
const int vmax=100005;
int par[vmax];
void init(int x){
  for(int i=0;i<x;i++){
    par[i]=i;
  }
}
int root(int x){
  if(par[x]==x){
    return x;
  }
  return par[x]=root(par[x]);
}
void unite(int x,int y){
  x=root(x);
  y=root(y);
  if(x==y){
    return ;
  }
  par[x]=y;
}
typedef long long ll;
int main(){
  int n;cin >> n;
  init(n);
  vector<pair<int,int>> a(n),b(n);
  for(int i=0;i<n;i++){
    int x,y;cin >> x >> y;
    a[i]=make_pair(x,i);
    b[i]=make_pair(y,i);
  }
  vector<pair<int,pair<int,int>>> c;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  for(int i=0;i<n-1;i++){
    int s=abs(a[i].first-a[i+1].first);
    int t=abs(b[i].first-b[i+1].first);
    c.push_back(make_pair(s,make_pair(a[i].second,a[i+1].second)));
    c.push_back(make_pair(t,make_pair(b[i].second,b[i+1].second)));
  }
  sort(c.begin(),c.end());
  ll ans=0;
  for(int i=0;i<c.size();i++){
    int u=c[i].second.first;
    int v=c[i].second.second;
    if(root(u)!=root(v)){
      ans+=c[i].first;
      unite(u,v);
    }
  }
  cout << ans << endl;
}