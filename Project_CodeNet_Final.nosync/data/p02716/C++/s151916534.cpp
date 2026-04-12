#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);++i)
#define chmax(x,y) x=max(x,y)
const ll INF = 1e18;
ll dp[200001][3]; // [N][skip]

int main() {
  int N; cin>>N;
  vector<int> A(N);
  rep(i, N) cin>>A[i];

  rep(i, N+1) dp[i][0] = dp[i][1] =  dp[i][2] =-INF;
  dp[0][0] = 0;

  rep(i, N){
		rep(k, N%2+1+1){
			chmax(dp[i+1][k], dp[i][k] + ((i+k)%2? 0:A[i]));
			if(k >= 2) break;
			chmax(dp[i+1][k+1], dp[i][k]);
		}
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
	// rep(j,N%2+1+1){
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
	// 	rep(j,N%2+1+1){
	// 		if(dp[i][j] == -INF) cout<<"----- ";
	// 		else printf("%5lld ",dp[i][j]);
	// 	}
	// 	puts("");
	// }
	// // ===========================

}
