#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<assert.h>
#include<string>
#include<cstdlib>
#include<cctype>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<stack>
// #include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 1LL<<60;
constexpr int inf = 1e9;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};

// intやllをstringに変換
template<typename T> inline string toString(const T &a){
  ostringstream oss;
  oss << a;
  return oss.str();
};
// ----------------------------------------------------------------------------
int dp[105][4][2];
int main(){
  string S;
  cin >> S;
  int N,K;
  N = S.size();
  cin >> K;
  dp[0][0][0] = 1;
  for(int i=0; i<N; i++){
    for(int j=0; j<4; j++){
      for(int k=0; k<2; k++){
        for(int d=0; d<10; d++){
          int nd = S[i] - '0';
          int nj = j;
          int nk = k;
          if(d != 0) nj++;
          if(nj > K) continue;
          if(k==0){
            if(nd < d) continue;
            if(nd > d) nk = 1;
          }
          dp[i+1][nj][nk] += dp[i][j][k];
        }
      }
    }
  }
  cout << dp[N][K][0] + dp[N][K][1] << endl;
  return 0;
}
