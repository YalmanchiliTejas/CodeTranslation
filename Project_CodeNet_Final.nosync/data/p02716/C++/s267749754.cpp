#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;
LL A[200001];
LL B[200001];
LL C[200001];
LL D[200001];
LL E[200001];
LL dp[5][200001];
int main(){
	cin>>N;
	REP(i,N){
		cin>>A[i];
	}
	REP(i,3){
		REP(j,N){
			dp[i][j]=-1e17;
		}
	}
	if(N==2){
		cout<<max(A[0],A[1])<<endl;
		return 0;
	}
	if(N==3){
		cout<<max(max(A[0],A[1]),A[2])<<endl;
		return 0;
	}
	dp[0][0]=A[0];
	dp[2][2]=A[2];
	dp[1][1]=A[1];
	dp[0][2]=A[0]+A[2];
	for(int i=3;i<N;i++){
		REP(j,3){
			dp[j][i]=max(dp[j][i-2]+A[i],dp[j][i]);
			dp[j+1][i]=max(dp[j][i-3]+A[i],dp[j+1][i]);
			if(i!=3){
				dp[j+2][i]=max(dp[j][i-4]+A[i],dp[j+2][i]);
			}
		}
	}
	LL answer=-1e17;
	REP(j,3){
		if(j==2&&N%2==0)continue;
		answer=max(answer,dp[j][N-1]);
	}
	cout<<answer<<endl;
	return 0;
}