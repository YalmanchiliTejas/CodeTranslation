#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> s(n);
  for(Int i=0;i<n;i++) cin>>s[i];

  Int ans=0;
  vector<Int> used(n,0);
  for(Int d=1;d<=n;d++){
    Int res=0;
    for(Int k=1;k*d<=n;k++){
      Int a=(n-1)-k*d;
      Int b=a-d;
      if(b<=0||a<=0||a>=n-1||b>=a) continue;
      assert(0<b&&b<a&&a<n-1);      
      assert(a*(k+1)-b*k==n-1);

      if(used[k*d]==d) break;      
      res+=s[k*d];
      used[k*d]=d;
      
      if(used[(n-1)-k*d]==d) break;
      res+=s[(n-1)-k*d];
      used[(n-1)-k*d]=d;
      
      chmax(ans,res);
    }
  }    
  cout<<ans<<endl;
  return 0;
}
