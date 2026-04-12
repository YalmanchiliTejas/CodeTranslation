#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll>P;
int N;
ll A[202020];

ll dp[202020][2][3];

int main() {
	string s;
	
	cin>>N;
	rep(i,N+1){ rep(x,2){ rep(y,3) dp[i][x][y]=-1e16;}}
	dp[0][1][0]=0;
	
	rep(i,N) {
      	ll x;
		cin>>x;
		rep(j,2) {
          rep(k,3) {
			// not take
			if(k+j<3) dp[i+1][1][k+j]=max(dp[i+1][1][k+j],dp[i][j][k]);
			// take
			if(j==1) dp[i+1][0][k]=max(dp[i+1][0][k],dp[i][j][k]+x);
		  }
        }
	}
	
	if(N%2==0) cout<<max(dp[N][1][0],dp[N][0][1])<<endl;
	else cout<<max(dp[N][0][2],dp[N][1][1])<<endl;
}