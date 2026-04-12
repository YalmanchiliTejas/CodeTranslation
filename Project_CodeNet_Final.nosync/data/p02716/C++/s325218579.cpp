#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
#define FOR(i,N) for(int i=0; i < (int)N; i++)
int N;
ll A[202020];
 
ll dp[202020][2][3];
 
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N+1) FOR(x,2) FOR(y,3) dp[i][x][y]=-1LL<<60;
	dp[0][1][0]=0;
	
	FOR(i,N) {
		cin>>x;
		FOR(j,2) FOR(k,3) {
			// not take
			if(k+j<3) dp[i+1][1][k+j]=max(dp[i+1][1][k+j],dp[i][j][k]);
			// take
			if(j==1) dp[i+1][0][k]=max(dp[i+1][0][k],dp[i][j][k]+x);
		}
	}
	
	if(N%2==0) cout<<max(dp[N][1][0],dp[N][0][1])<<endl;
	else cout<<max(dp[N][0][2],dp[N][1][1])<<endl;
}

int main(){
	solve();
}