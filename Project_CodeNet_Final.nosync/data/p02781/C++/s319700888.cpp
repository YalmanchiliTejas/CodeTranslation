#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

ll dp[105][4][2];

int main(){
  string n;
  cin >> n;
  int sz=n.size();
  int k;
  cin >> k;

  rep(i, sz)rep(j, k+1)rep(l, 2){
    dp[i][j][l]=0;
  }
  dp[0][0][0]=1;
  /*
  rep(i, sz)rep(j, k+1)rep(l, 2){
    int nsz=n[sz-i-1]-'0';
    rep(dig, 10){
      if(dp[i][j][l]>1e9)continue;
      if(dig==0 && nsz>0){
        if(dp[i+1][j][0]>1e9)continue;
        dp[i+1][j][0]+=dp[i][j][l];
      } else if(dig==0 && nsz==0){
        if(dp[i+1][j][l]>1e9)continue;
        dp[i+1][j][l]+=dp[i][j][l];
      } else if(nsz>dig && dig!=0 && j+1<=k){
        if(dp[i+1][j+1][0]>1e9)continue;
        dp[i+1][j+1][0]+=dp[i][j][l];
      } else if(nsz==dig && dig!=0 && j+1<=k){
        if(dp[i+1][j+1][l]>1e9)continue;
        dp[i+1][j+1][l]+=dp[i][j][l];
      } else if(nsz<dig && dig!=0 && j+1<=k){
        if(dp[i+1][j+1][1]>1e9)continue;
        dp[i+1][j+1][1]+=dp[i][j][l];
      }
    }

  }*/

  rep(i, sz)rep(j, k+1)rep(l, 2){
    int nsz=n[i]-'0';
    rep(dig, 10){
      if(dig==0 && nsz>0){
        dp[i+1][j][1]+=dp[i][j][l];
      } else if(dig==0 && nsz==0){
        dp[i+1][j][l]+=dp[i][j][l];
      } else if(nsz>dig && dig!=0 && j+1<=k){
        dp[i+1][j+1][1]+=dp[i][j][l];
      } else if(nsz==dig && dig!=0 && j+1<=k){
        dp[i+1][j+1][l]+=dp[i][j][l];
      } else if(nsz<dig && j+1<=k && l==1){
        dp[i+1][j+1][l]+=dp[i][j][l];
      }
    }
  }

  cout << dp[sz][k][1]+dp[sz][k][0] << endl;
  return 0;
}
