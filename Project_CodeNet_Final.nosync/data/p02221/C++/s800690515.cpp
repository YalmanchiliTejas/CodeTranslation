#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int N;
int POW[22],dp[20][1 << 20];
int P[1 << 20];
string line;

int main(){

	POW[0] = 1;
	for(int i = 1; i < 21; i++){

		POW[i] = POW[i-1]*2;
	}

	scanf("%d",&N);

	cin >> line;

	for(int i = 0; i < POW[N]; i++){

		scanf("%d",&P[i]);
		P[i+POW[N]] = P[i];
	}

	for(int i = 0; i < 2*POW[N]; i++){

		dp[0][i] = P[i];
	}

	for(int i = 0; i < N; i++){
		for(int k = 0; k+POW[i] < 2*POW[N]; k++){

			int loc = max(dp[i][k],dp[i][k+POW[i]])-min(dp[i][k],dp[i][k+POW[i]]);

			if(line[loc-1] == '1'){

				dp[i+1][k] =  max(dp[i][k],dp[i][k+POW[i]]);

			}else{

				dp[i+1][k] = min(dp[i][k],dp[i][k+POW[i]]);
			}
		}
	}

	for(int i = 0; i < POW[N]; i++){

		printf("%d\n",dp[N][i]);
	}

	return 0;
}

