#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main(){
  ll n,x,m,i,j,d,q,r,ans;
  cin>>n>>x>>m;
  vector<ll> a(m+1),b(m+2);
  a[0]=x; b[1]=x;
  set<ll> s={x};
  for(i=1;i<m+1;i++){
    a[i]=a[i-1]*a[i-1]%m;
    b[i+1]=b[i]+a[i];
    if(i==n-1){
      cout<<b[n]<<endl;
      return 0;
    }
    else if(s.count(a[i])) break;
    else s.insert(a[i]);
  }
  for(j=0;j<i;j++) if(a[j]==a[i]) break;
  d=i-j;
  q=(n-i)/d;
  r=(n-i)%d;
  ans=b[i]+q*(b[i+1]-b[j+1]);
  if(r>0) ans+=b[j+r]-b[j];
  cout<<ans<<endl;
}