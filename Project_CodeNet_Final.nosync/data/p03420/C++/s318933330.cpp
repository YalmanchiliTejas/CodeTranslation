#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define BIG 1000000010
#define EPS 1e-9
#define fst first
#define scd second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int n,k;
  cin>>n>>k;
  int ans=0;
  repi(i,k+1,n+1){
    ans+=(n/i)*(i-k)+max((int)0,(n%i)-k+1);
    //cout<<ans<<endl;
  }
  if(k==0) ans=n*n;
  cout<<ans<<endl;

  return 0;
}