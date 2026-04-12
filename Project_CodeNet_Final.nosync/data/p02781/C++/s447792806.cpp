#include <bits/stdc++.h>
using namespace std;
string n;int k,ans,ze[10000];
template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
bool zero(int a,int b){
  return !(ze[n.size()-b-1]-ze[n.size()-a]);
}
void f(vector<int> &v){
  int yo,giri;
  if(v[0]+1==n.size())yo=n[0]-'0'-1,giri=1;
  else yo=9,giri=0;
  for(int i=1;i<k;i++){
    if(zero(v[i-1],v[i])){
      yo*=9;
      if(n[n.size()-1-v[i]]=='0')giri=0;
      yo+=giri*(n[n.size()-1-v[i]]-'0'-1);
    }
    else{
      yo+=giri;
      giri=0;
      yo*=9;
    }
  }
  ans+=yo+giri;
}
void g(vector<int> &v){
  f(v);
  v[k-1]++;
  for(int i=1;i<k;i++)if(v[k-i-1]==v[k-i])v[k-i]=0,v[k-i-1]++,i=0;
  if(v[0]==n.size())fin(ans);
}
signed main(){
  cin>>n>>k;
  if(n.size()<k)fin(0);
  vector<int> v(k);
  for(int i=0;i<k;i++)v[i]=k-i-1;
  for(int i=0;i<n.size();i++)ze[i+1]=ze[i]+n[i]-'0';
  while(1)g(v);
}
