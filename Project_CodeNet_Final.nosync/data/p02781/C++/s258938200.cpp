#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <set>
#define INF 1000000000
#define LLINF 2000000000000000
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define LOOP(i,N) for(int i=0;i<N;i++)
#define LOOP1(i,N) for(int i=1;i<=N;i++)
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
// #define int long long

signed main(){
  string n;
  int k;
  cin >> n >> k;
  int a[n.length()];
  LOOP(i,n.length()){
    a[i] = n[i]-'0';
    // if(a[i]==0)a[i]=0;
  }
  int dp[101][4][2] = {};
  int l = n.length();
  dp[0][0][true] = 1;
  LOOP(i,l){
    if(i!=0)  dp[i][0][false] = 1;
    LOOP(j,3){
      // dp[i+1][j][false] += dp[i][j][true] + dp[i][j][false]; // 0をi桁目に入れる
      if(a[i] == 0){
        dp[i+1][j+1][true] += dp[i][j+1][true];
        dp[i+1][j+1][false] += dp[i][j+1][false] + dp[i][j][false]*9;
      }else{
        dp[i+1][j+1][true] += dp[i][j][true];
        dp[i+1][j+1][false] += dp[i][j][true]*(a[i]-1) + dp[i][j][false] * 9;
        dp[i+1][j+1][false] += dp[i][j+1][true] + dp[i][j+1][false];
      }
    }
  }
  // LOOP(i,n.length()+1){
  //   LOOP(j,4){
  //     cerr << dp[i][j][false] << ":" << dp[i][j][true] << " ";
  //   }cerr << endl;
  // }
  cout << dp[n.length()][k][false] + dp[l][k][true] << endl;
}
