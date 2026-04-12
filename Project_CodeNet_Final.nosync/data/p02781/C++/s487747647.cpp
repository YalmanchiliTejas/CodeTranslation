#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

ll dp[110][2][4];

int main(){
  string S;
  cin>>S;
  int N=S.size();
  int K;
  cin>>K;

  dp[0][0][0]=1;
  for(int i=0;i<N;i++){
    for(int k=0;k<2;k++){
      for(int l=0;l<=K;l++){
        for(int m=0;m<2;m++){
          if(m==0){
            int nk=k,nl=l;
            if(S[i]-'0'!=0) nk=1;
            dp[i+1][nk][nl]+=dp[i][k][l];
          }else{
            for(int p=1;p<=9;p++){
              int nk=k,nl=l+1;
              if(nl>K) continue;
              if(k==0&&S[i]-'0'>p) nk=1;
              if(k==0&&S[i]-'0'<p) continue;
              dp[i+1][nk][nl]+=dp[i][k][l];
            }
          }
        }
      }
    }
  }

  ll ans=0;
  rep(k,2) ans+=dp[N][k][K];
  cout<<ans<<endl;

  return 0;
}
