#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int N; cin>>N;
	long A[N];
	rep(i,0,N) cin>>A[i];
	long dp[N][N];
	rep(i,0,N) dp[i][i] = A[i];
	rep(i,1,N){
		rep(j,0,N-i){
			dp[j][j+i] = max(A[j] - dp[j+1][j+i], A[j+i] - dp[j][j+i-1]);
		}
	}cout<<dp[0][N-1]<<endl;
}