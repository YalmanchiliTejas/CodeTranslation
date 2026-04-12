#include<bits/stdc++.h>
using namespace std;
void f(int n,int64_t x,vector<int64_t> &l,vector<int64_t> &p,int64_t &ans){
  if(x==1) return;
  else if(x<l.at(n-1)+1) f(n-1,x-1,l,p,ans);
  else if(x==l.at(n-1)+1) ans+=p.at(n-1);
  else if(x==l.at(n-1)+2) ans+=p.at(n-1)+1;
  else if(x<2*l.at(n-1)+2){
    ans+=p.at(n-1)+1;
    f(n-1,x-l.at(n-1)-2,l,p,ans);
  }
  else if(x>=2*l.at(n-1)+2) ans+=p.at(n);
}
int main(){
  int n,i;
  int64_t x,ans=0;
  cin>>n>>x;
  vector<int64_t> l(n+1),p(n+1);
  l.at(0)=1;
  p.at(0)=1;
  for(i=1;i<=n;i++){
    l.at(i)=2*l.at(i-1)+3;
    p.at(i)=2*p.at(i-1)+1;
  }
  f(n,x,l,p,ans);
  cout<<ans<<endl;
}