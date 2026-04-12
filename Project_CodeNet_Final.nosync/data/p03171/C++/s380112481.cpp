#include<bits/stdc++.h>
//L:Deque

using namespace::std;

const int SIZE = 3e3 + 1;
int A[SIZE];
long long DP[SIZE][SIZE][2],TA[SIZE];

long long suma(int i,int f){
	return TA[f] - TA[i - 1];
}

long long dp(int i,int j,int p){
	if(!DP[i][j][p]){
		DP[i][j][p] = suma(i,j) - min(dp(i + 1,j,!p),dp(i,j - 1,!p));
	}
	return DP[i][j][p];	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for(int i = 1;i <= N;i++){
		cin >> A[i];
		TA[i] = TA[i - 1] + A[i];
		DP[i][i][0] = DP[i][i][1] = A[i];
	}

	long long j1 = dp(1,N,0);
    long long j2 = suma(1,N) - j1;

	cout << j1 - j2 << '\n';
	
	return 0;
}
