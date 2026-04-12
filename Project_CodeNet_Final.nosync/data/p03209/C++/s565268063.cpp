#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,x;
  cin>>n>>x;
  vector<Int> a(n+1,1),b(n+1,1);
  for(Int i=1;i<=n;i++){
    a[i]=1+a[i-1]+1+a[i-1]+1;
    b[i]=b[i-1]+1+b[i-1];
  }
  Int ans=0;
  for(Int i=n;i>=1;i--){
    if(x==0) break;
    x--;
    if(x<=a[i-1]) continue;
    ans+=b[i-1]+1;
    x-=a[i-1]+1;
  }
  if(x) ans++;
  cout<<ans<<endl;
  return 0;
}
