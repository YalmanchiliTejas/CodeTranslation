#include <bits/stdc++.h>

using namespace std;

const int MAXN=3100;

struct elem{
	long long int first;
	long long int second;
};

elem dp[MAXN][MAXN];
long long int A[MAXN];
int N;
void calcDP(){
	for(int i=0;i<N;i++)
		dp[i][i].first=A[i];
	for(int offset=1;offset<N;offset++){
		for(int i=0;i+offset<N;i++){
			if((A[i]+dp[i+1][i+offset].second-dp[i+1][i+offset].first)>A[offset+i]+dp[i][i+offset-1].second-dp[i][i+offset-1].first)
				dp[i][i+offset].first=A[i]+dp[i+1][i+offset].second,dp[i][i+offset].second=dp[i+1][i+offset].first;
			else
				dp[i][i+offset].first=A[offset+i]+dp[i][i+offset-1].second,dp[i][i+offset].second=dp[i][i+offset-1].first;
		}
	}
}
int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>A[i];
	calcDP();
	cout<<dp[0][N-1].first-dp[0][N-1].second;
}