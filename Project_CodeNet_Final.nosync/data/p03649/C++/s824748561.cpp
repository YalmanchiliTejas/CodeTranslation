#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n;
  cin>>n;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];
  ll ans=0;
  while(1){
    bool go=true;
    rep(i,n){
      if(a[i]>=n){
        go=false;
        ans+=a[i]/n;
        rep(j,n){
          if(i!=j){
            a[j]+=a[i]/n;
          }
        }
      }
      a[i]%=n;
    }
    if(go)break;
  }
  cout<<ans<<endl;
}