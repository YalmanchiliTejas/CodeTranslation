#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename F>
struct FixPoint : F{
  FixPoint(F&& f):F(forward<F>(f)){}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) const{
    return F::operator()(*this,forward<Args>(args)...);
  }
};
template<typename F>
inline decltype(auto) MFP(F&& f){
  return FixPoint<F>{forward<F>(f)};
}

//INSERT ABOVE HERE
Int dp[2][5][101]={};
signed main(){
  string s;
  cin>>s;
  Int k;
  cin>>k;
  Int n=s.size();
  dp[0][0][0]=1;
  for(Int i=0;i<n;i++){
    for(Int f=0;f<2;f++){
      for(Int c=0;c<4;c++){
        for(Int k=0;k<=(f?9:s[i]-'0');k++){
          Int nf=f||(k<s[i]-'0');
          Int nc=c+(k!=0);
          dp[nf][nc][i+1]+=dp[f][c][i];
        }
      }
    }
  }
  cout<<dp[0][k][n]+dp[1][k][n]<<endl;
  return 0;
}
