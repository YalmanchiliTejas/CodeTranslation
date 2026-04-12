#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,n) for(int i=a;i<n;i++)

#define MAX (300+10)

string s;
int dp[MAX][MAX];

string lcs(string a, string b){
  memset(dp, -1, 0);
  rep(i,a.size()+1) dp[i][0] = 0;
  rep(j,b.size()+1) dp[0][j] = 0;
  for(int i=1;i<=a.size();i++){
    for(int j=1;j<=b.size();j++){
      if(a[i-1] == b[j-1]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  
  // rep(i,a.size()+1) {
  //   rep(j,b.size()+1){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  
  string s = "";
  int i = a.size(), j = b.size();
  while(dp[i][j] != 0){
    if(a[i-1] == b[j-1]){
      s = s + a[i-1];
      i--; j--;
    }
    else if(dp[i][j] == dp[i-1][j]){
      i--;
    }
    else{
      j--;
    }
  }
  
  reverse(s.begin(), s.end());
  
  return s;
}

void solve(){
  string res = "";
  for(int i=1;i<s.size();i++){
    string a = s.substr(0, i);
    string b = s.substr(i, s.size()-i);
    string r = lcs(a, b);
    
    if(r.size() > res.size()) res = r;
  }
  
  cout << res << endl;
}

int main(){
  while(true){
    cin >> s;
    if(s == "#END") break;
    solve();
  }
}