#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//X+Y = C and Y=C-X. 
//Therefore X-Y = 2X - C. So A tries to maximise X and B tries to maximize X as C=(sum of A[i]) is constant

//State
//dp[i][j][k]: The number of points A has
//	when the queue to choose from is (A[i]....A[j]) where player k starts first

//Initialization
//dp[i][i] = A[i]

//Transitions
//if(i+N-1-j %2 == 0) dp[i][j] = max(dp[i+1][j]+A[i], dp[i][j-1]+A[j])
//else dp[i][j] = min(dp[i+1][j]+A[i], dp[i][j-1]+A[j])

//Order of evaluation
//Diagonally or Length of substring wise

//Answer
//dp[0][N-1]

long long dp[3005][3005][2];
int A[3005];

int main(){
	int N; long long C=0;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> A[i];
		dp[i][i][0] = A[i];
		dp[i][i][1] = 0;
		C = C+A[i];
	}
	
	for(int rMinusl=1; rMinusl<N; rMinusl++){
		for(int l=0; l<N; l++){
		    int r = l+rMinusl;
			if(r<N){
				dp[l][r][0] = max(dp[l+1][r][1]+A[l], dp[l][r-1][1]+A[r]);
			    dp[l][r][1] = min(dp[l+1][r][0], dp[l][r-1][0]);
			}   
		}
	}
	
	cout << 2*dp[0][N-1][0]-C << endl;
}
