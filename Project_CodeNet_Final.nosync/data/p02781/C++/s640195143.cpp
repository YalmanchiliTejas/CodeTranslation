#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
#include<numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int dp[105][4][2];

int main(){
  string s;
  cin >> s;
  int K;
  cin >> K;
  dp[0][0][0]=1;
  rep(i,s.size())rep(j,4)rep(k,2){
    int nd = s[i]-'0';
    rep(d,10){
      int ni,nj,nk;
      ni = i+1;
      if(d!=0)nj=j+1;
      else nj=j;
      if(nj>3)continue;
      if(k==1)nk=1;
      else{
        if(nd < d)continue;
        else if(nd==d)nk=0;
        else nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  cout << dp[s.size()][K][0]+dp[s.size()][K][1] << endl;
}