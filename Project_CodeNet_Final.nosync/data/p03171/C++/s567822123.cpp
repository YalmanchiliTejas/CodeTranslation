#include <bits/stdc++.h>
using namespace std;

#define M 3000
#define ll long long

ll N,v[M],dp[M][M],sum;

inline ll sol (int i, int j, long long sum)
{
	if(i==j) return dp[i][j]=v[i];
	if(dp[i][j]!=-1) return dp[i][j];
	
	return dp[i][j]=max(sum-sol(i+1,j,sum-v[i]),sum-sol(i,j-1,sum-v[j]));
}


int main ()
{
	cin >> N;
	for(int i=0; i<N; i++) { cin >> v[i]; sum+=v[i]; }
	for(int i=0; i<M; i++) for(int j=0; j<M; j++) dp[i][j]=-1;
	cout << sol(0,N-1,sum) - (sum - dp[0][N-1]);
}