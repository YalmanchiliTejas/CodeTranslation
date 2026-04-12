#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=998244353;

struct p{ll gb,cnt,rui;};
p dp[3005][3005];
void f(p &a,p b){
  a={(a.gb+a.rui*a.cnt+b.gb+b.rui*b.cnt)%MOD,0,(a.rui+b.rui)%MOD};
}
int g(p a){
  return a.gb+a.rui*a.cnt%MOD;
}
ll n,s,ans;

signed main(){
  cin>>n>>s;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  for(int i=0;i<n;i++){
    f(dp[i+1][v[i]],{0,1,i+1});
    for(int j=1;j<=s;j++){
      if(j+v[i]<=s)f(dp[i+1][j+v[i]],dp[i][j]);
      f(dp[i+1][j],dp[i][j]);
    }
    ans+=g(dp[i+1][s]);
  }
  cout<<ans%MOD<<endl;
}
