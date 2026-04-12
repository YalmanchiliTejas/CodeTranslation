#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int DP[3100][3100] = {};

int main(){
	
	int N;
	cin >> N;
	
	int a[3100];
	for(int i = 1; i <= N; i++){
		cin >> a[i];
	}
	
	for(int i = 2; i <= N + 1; i++){
		for(int j = 0; i + j <= N + 1; j++){
			if((N - i) % 2){
				DP[j][i] = max(DP[j][i - 1] + a[j + i - 1], DP[j + 1][i - 1] + a[j + 1]);
			}else{
				DP[j][i] = min(DP[j][i - 1] - a[j + i - 1], DP[j + 1][i - 1] - a[j + 1]);
			}
			//cout << j << " " << i + j << " " << DP[j][i] << endl;
		}
	}
	
	cout << DP[0][N + 1] << endl;
	
	return 0;
}
