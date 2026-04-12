#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000010
#define EPS 1e-9
#define fst first
#define scd second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int a[12];
  rep(i,12) cin>>a[i];
  sort(a,a+12);
  for(int i=0;i<12;i+=4){
    for(int j=i;j<i+4;j++){
      if(a[i]!=a[j]){cout<<"no"<<endl;return 0;}
    }
  }
  cout<<"yes"<<endl;
      

  return 0;
}

