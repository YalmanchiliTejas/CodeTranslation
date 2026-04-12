#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,x,m;
  cin>>n>>x>>m;
  if(n<m){
    int64_t a=0;
    for(int64_t i=x,j=0;j<n;i=i*i%m,j++)
      a+=i;
    cout<<a<<endl;
    return 0;
  }
  vector<int64_t> c(m,0);
  vector<int64_t> o(m,m);
  int l=m;
  int p=m;
  for(int64_t i=x,j=0;;i=i*i%m,j++){
    if(c.at(i)!=0){
      l=i;
      p=j-o.at(i);
      break;
    }
    c.at(i)++;
    o.at(i)=j;
  }
  for(int64_t i=l,j=0;j<p;i=i*i%m,j++){
    c.at(i)=0;
    c.at(i)+=(n-o.at(l))/p+(j<(n-o.at(l))%p?1:0);
  }
  int64_t s=0;
  for(int i=0;i<m;i++)
    s+=c.at(i)*i;
  cout<<s<<endl;
}