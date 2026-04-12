//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
#define int long long
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
    const int MAX =3001;
const int MOD =998244353;


  
signed main(){
  int n,x,m;
  cin>>n>>x>>m;
  int k=1,s[m]={};
  while(s[x]==0){
    s[x]=k;
    k++;
    x=x*x%m;
  }
  int ans=0;
  
  for(int i=0;i<m;i++){
    if(s[i]==0)continue;
    if(s[i]<s[x]&&s[i]<=n){
      ans+=i;
      continue;
    }
   if(s[i]<=n) ans+=i*(1+(n-s[i])/(k-s[x]));

  }
  cout<<ans<<endl;

}