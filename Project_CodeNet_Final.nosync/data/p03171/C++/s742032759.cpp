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
			long long int firstX = A[i]+dp[i+1][i+offset].second;
			long long int firstY = dp[i+1][i+offset].first;
			long long int secondX = A[offset+i] + dp[i][i+offset-1].second;
			long long int secondY = dp[i][i+offset-1].first;
			if((firstX-firstY)>secondX-secondY){
				dp[i][i+offset].first=firstX;
				dp[i][i+offset].second=firstY;
			}
			else{
				dp[i][i+offset].first=secondX;
				dp[i][i+offset].second=secondY;
			}
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