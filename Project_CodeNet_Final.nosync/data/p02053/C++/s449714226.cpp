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
  int h,w;
  cin>>h>>w;
  vector<int> a,b;
  int ans=0;
  rep(i,h){
    rep(j,w){
      char c;
      cin>>c;
      if(c=='B'){
	a.push_back(i+j);
	b.push_back(i+w-j-1);
	//cout<<i+j<<endl;
      }
    }
  }
  sort(a.begin(),a.end() );
  ans=max(ans,a[a.size()-1]-a[0]);
  sort(b.begin(),b.end() );
  ans=max(ans,b[b.size()-1]-b[0]);
  cout<<ans<<endl;

  return 0;
}

