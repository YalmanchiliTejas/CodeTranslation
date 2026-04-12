#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)

int main(){
  int N;cin>>N;
  vector<int> H(N),W(N);
  rep(i,0,N)cin>>H[i]>>W[i];
  int C[4][4];
  int goals[3] = {};
  rep(i,0,4)rep(j,0,4){
    char c;cin>>c;
    if(c=='R')
      C[i][j]=0;
    else if(c=='G')
      C[i][j]=1;
    else 
      C[i][j]=2;
    goals[C[i][j]] |= 1 << (i * 4 + j);
  }
  vector<int> stamps;
  auto inrange = [&](int i,int j) {return 0 <= i && i < 4 && 0 <= j && j < 4; };
  rep(s,0,N){
    rep(i,-3,4)rep(j,-3,4){
      int mask = 0;
      rep(ci,i,i+H[s])rep(cj,j,j+W[s]){
        if(!inrange(ci,cj))continue;
        mask |= (1 << (ci * 4 + cj));
      }
      stamps.push_back(mask);
    }
  }
  queue<int> q;
  q.push(0);
  const int INF = 100;
  vector<int> dp(1 << 16, INF);
  dp[0] = 0;
  while(q.size()) {
    int now = q.front(); q.pop();
    rep(c,0,3){
    for(auto stamp : stamps){
      int next = (~stamp & now) | (goals[c] & stamp);
      if(dp[next] != INF)continue;
      dp[next] = dp[now] + 1;
      q.push(next);
    }
    }
  }
  
  cout << dp[(1 << 16) - 1] << endl;

  return 0;
}

