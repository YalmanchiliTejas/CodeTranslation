#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>
#include <list>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
	int N, S;
	int A[3001];
	cin >> N >> S;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
	}
	
	static ll DP[3002][3002][3];
	for(int s = 0; s <= 3001; s++){
		DP[0][s][0] = 0;
		DP[0][s][1] = 0;
		DP[0][s][2] = 0;
	}
	DP[0][0][0] = 1;
	
	for(int n = 1; n <= N; n++){
		for(int s = 0; s <= S; s++){
			DP[n][s][0] = DP[n-1][s][0];
			DP[n][s][1] = DP[n-1][s][1] + DP[n-1][s][0];
			DP[n][s][2] = DP[n-1][s][2];
			
			if(s >= A[n]){
				DP[n][s][1] += DP[n-1][s-A[n]][1] + DP[n-1][s-A[n]][0];
			}
			
			if(s == S){
				DP[n][s][2] += DP[n][s][1];
			}
			
			for(int t = 0; t < 3; t++){
				DP[n][s][t] %= 998244353;
			}
		}
	}
	
	cout << DP[N][S][2] << endl;
	
	return 0;
}