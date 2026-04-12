//sunuke さんのコード
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);++i)
#define chmax(x,y) x=max(x,y)
const ll INF = 1e18;
ll dp[200001][4]; // [N][skip]

int main() {
  int N; cin>>N;
  vector<int> A(N);
  rep(i, N) cin>>A[i];

  rep(i, N+1) dp[i][0] = dp[i][1] =  dp[i][2] =-INF;
  dp[0][0] = 0;

  rep(i, N){

		chmax(dp[i+1][1], dp[i][0]);
		chmax(dp[i+1][0], dp[i][0] + ((i+0)%2? 0:A[i]));

		chmax(dp[i+1][2], dp[i][1]);
		chmax(dp[i+1][1], dp[i][1] + ((i+1)%2? 0:A[i]));

		chmax(dp[i+1][3], dp[i][2]);
		chmax(dp[i+1][2], dp[i][2] + ((i+2)%2? 0:A[i]));

  }

  cout << dp[N][N%2+1] << endl;

	// // print =====================
	// puts("---");//
	// rep(i,N)cout<<A[i]<<" ";//
	// puts("");//
	// puts("===");//
	// cout<<"i: ";
	// rep(i,N+1) printf("%5d ",i);//
	// puts("");//
	// rep(j,skip+1){
	// 	cout<<j<<": ";
	// 	rep(i,N+1){
	// 		if(dp[i][j] == -INF) cout<<"----- ";
	// 		else printf("%5lld ",dp[i][j]);
	// 	}
	// 	puts("");
	// }
	// puts("===");//
	// rep(i,N+1){
	// 	cout<<i<<": ";
	// 	rep(j,skip+1){
	// 		if(dp[i][j] == -INF) cout<<"----- ";
	// 		else printf("%5lld ",dp[i][j]);
	// 	}
	// 	puts("");
	// }
	// // ===========================

}
