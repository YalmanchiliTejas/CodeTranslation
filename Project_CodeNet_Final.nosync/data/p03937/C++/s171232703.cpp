#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)
char mp[10][10];
int dp[10][10];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  int h,w;
  cin>>h>>w;
  rep(i,h) {
    string s;
    cin>>s;
    rep(j,w) {
      mp[i][j] = s[j];
    }
  }
  dp[0][0] = 1;
  repeat(j,1,w) {
    dp[0][j]=0;
    if(mp[0][j-1]=='#'&&mp[0][j]=='#') dp[0][j] +=dp[0][j-1];
  }
  repeat(i,1,h) {
    dp[i][0]=0;
    if(mp[i-1][0]=='#'&&mp[i][0]=='#') dp[i][0]+=dp[i-1][0];
  }
  repeat(i,1,h) {
    repeat(j,1,w) {
      dp[i][j]=0;
      if(mp[i][j]=='#') {
        if(mp[i-1][j]=='#') dp[i][j]+=dp[i-1][j];
        if(mp[i][j-1]=='#')dp[i][j]+=dp[i][j-1];
      }
    }
  }
  // rep(i,h) {
  //   rep(j,w) {
  //     cout << dp[i][j];
  //   }
  //   cout << endl;
  // }
  int c=0;
  rep(i,h) {
    rep(j,w) {
      if(mp[i][j]=='#'&&dp[i][j]!=1) {
        cout << "Impossible"<<endl;
        return 0;
      }
      if(mp[i][j]=='#')c++;
    }
  }
  if(c==h+w-1)
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
  return 0;
}
