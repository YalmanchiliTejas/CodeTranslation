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
  int n;
  cin>>n;
  int a[50];
  rep(i,n) cin>>a[i];
  int ans=0;
  while(1){
    bool f=true;
    sort(a,a+n,greater<int>() );
    if(a[0]>=n){
      f=false;
      int num=a[0]/n;
      a[0]%=n;
      ans+=num;
      //cout<<a[0]<<endl;
      repi(j,1,n) a[j]+=num;
    }
    if(f) break; 
  }
  cout<<ans<<endl;
  return 0;
}