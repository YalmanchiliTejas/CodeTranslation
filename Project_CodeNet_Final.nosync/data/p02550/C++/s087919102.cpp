#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(void){
  ll n,x,m; cin>>n>>x>>m; --n;
  vector<bool> c(m,false);
  ll res=x;
  while(n-->0){
    x=x*x%m;
    if(c[x]==false) res+=x,c[x]=true;
    else{
      ll cnt=0,cnt2=0;
      vector<bool> d(m,false);
      while(d[x]==false){
        cnt+=x;
        d[x]=true;
        x=x*x%m;
        ++cnt2;
      }
      res+=cnt*(n/cnt2);
      n-=n/cnt2*cnt2;
      while(n-->=0) res+=x,x=x*x%m;
    }
  }
  cout<<res;
  return 0;
}
