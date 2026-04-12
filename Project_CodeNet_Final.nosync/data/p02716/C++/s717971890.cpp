#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);++i)
#define chmax(x,y) x=max(x,y)
const ll INF = 1e18;
ll dp[200001][4]; // [N+1][skip+1]

int main() {
  int N; cin>>N;
  vector<int> A(N);
  rep(i, N) cin>>A[i];

  rep(i, N+1) rep(j, 4) dp[i][j] =-INF;
  dp[0][0] = 0;

  rep(i, N){
		rep(k, 3){
			chmax(dp[i+1][k], dp[i][k] + ((i+k)%2? 0:A[i]));
			chmax(dp[i+1][k+1], dp[i][k]);
		}
  }

  cout << dp[N][N%2+1] << endl;

}
