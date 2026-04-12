#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
inline string smax(string &s, string &t){
  return (s.size() < t.size()) ? t : s;
}
int main(){
  string s;
  while(cin>>s && s != "#END"){
    string ans = "";
    for(int dif = 0; dif < s.size()/2 + 1; dif++){
      {
        int i = s.size() / 2 + dif;
        if(i < s.size() && i > 0 && min(i, (int)s.size() - i) > ans.size()){
          int numdp[301][301] = {};
          string dp[301][301] = {};
          for(int j = 0; j < i; j++){
            for(int k = i; k < s.size(); k++){
              if(s[j] == s[k]) numdp[j+1][k+1] = numdp[j][k] + 1;
              else numdp[j+1][k+1] = max(numdp[j][k+1], numdp[j+1][k]);
            }
          }
          if(ans.size() < numdp[i][s.size()]){
            for(int j = 0; j < i; j++){
              for(int k = i; k < s.size(); k++){
                if(s[j] == s[k]) dp[j+1][k+1] = dp[j][k] + s[j];
                else dp[j+1][k+1] = smax(dp[j][k+1], dp[j+1][k]);
              }
            }
            ans = dp[i][s.size()];
          }
        }
      }
      {
        int i = s.size() / 2 - dif;
        if(i < s.size() && i > 0 && min(i, (int)s.size() - i) > ans.size()){
          int numdp[301][301] = {};
          string dp[301][301] = {};
          for(int j = 0; j < i; j++){
            for(int k = i; k < s.size(); k++){
              if(s[j] == s[k]) numdp[j+1][k+1] = numdp[j][k] + 1;
              else numdp[j+1][k+1] = max(numdp[j][k+1], numdp[j+1][k]);
            }
          }
          if(ans.size() < numdp[i][s.size()]){
            for(int j = 0; j < i; j++){
              for(int k = i; k < s.size(); k++){
                if(s[j] == s[k]) dp[j+1][k+1] = dp[j][k] + s[j];
                else dp[j+1][k+1] = smax(dp[j][k+1], dp[j+1][k]);
              }
            }
            ans = dp[i][s.size()];
          }
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}