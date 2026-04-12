#include <bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
template<typename T>
void chmin(T &a,T b){
  if(a>b)a=b;
}
template<typename T>
void chmax(T &a,T b){
  if(a<b)a=b;
}
using ld=long double;
const int INF=1e9;
const int MOD=998244353;
struct p{
  int gb,cnt,rui;
};
p dp[3005][3005];
void f(p &a,p b){
  int gb=a.gb+a.rui*a.cnt+b.gb+b.rui*b.cnt;
  int cnt=0;
  int rui=a.rui+b.rui;
  a={gb%MOD,0,rui%MOD};
}

signed main(){
  int n,s;cin>>n>>s;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  for(int i=0;i<3005;i++)for(int j=0;j<3005;j++)dp[i][j]={0,0,0};
  int ans=0;
  for(int i=0;i<n;i++){
    f(dp[i+1][v[i]],{0,1,i+1});
    for(int j=1;j<=s;j++){
      if(j+v[i]<=s)f(dp[i+1][j+v[i]],dp[i][j]);
      f(dp[i+1][j],dp[i][j]);
    }
    ans+=(dp[i+1][s].gb+dp[i+1][s].rui*dp[i+1][s].cnt%MOD)%MOD;ans%=MOD;
  }
  cout<<ans<<endl;
}
