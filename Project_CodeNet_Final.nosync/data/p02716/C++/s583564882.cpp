#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
const ll MAX_N=2e5;
ll N,A[MAX_N],dp[MAX_N],psm[MAX_N];
int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin>>N;
	REP(i,N){
		cin>>A[i];
	}
	psm[0]=A[0];
	for(ll i=2;i<N;i+=2){
		psm[i]=psm[i-2]+A[i];
	}
	dp[0]=0;
	dp[1]=max(A[0],A[1]);
	FOR(i,2,N){
		if(i%2==0){
			dp[i]=max(dp[i-1],A[i]+dp[i-2]);
		}else{
			dp[i]=max(psm[i-1],A[i]+dp[i-2]);
		}
	}
	cout<<dp[N-1]<<endl;
}