#include <iostream>
#include <string>
using namespace std;

long long int MOD = 1000000007;

long long int dp[10006][105][2];

string S;

int D;

int A[10008];

int main(void) {


	cin >> S;
	cin >> D;

	int M = S.size();

	int q = 1;
	for (int j = M - 1; j >= 0; j--) {
		A[q++] = S[j] - '0';\
	}
	q--;

	dp[q][A[q] % D][0] = 1;
	for (int i = 0; i < A[q]; i++) {
		dp[q][i%D][1] += 1;
	}

	/*for (int i = 1; i <= 12; i++) {
		cout << "A[" << i << "]= " << A[i] << endl;
	}*/

	for (int i = q-1; i >= 1; i--) {
		//===========
		for (int k = 0; k < D; k++) {
			for (int a = 0; a <= 9; a++) {
				dp[i][(k + a) % D][1] += dp[i+1][k][1];
				dp[i][(k + a) % D][1] %= MOD;
			}
		}
		//==============
		for (int k = 0; k < D; k++) {
			dp[i][(k + A[i]) % D][0] += dp[i+1][k][0]; 
			dp[i][(k + A[i]) % D][0] %= MOD;
			for (int a = 0; a < A[i]; a++) {
				dp[i][(k + a) % D][1] += dp[i+1][k][0];
				dp[i][(k + a) % D][1] %= MOD;
			}
		}
	}

	long long int ans = (dp[1][0][1]+dp[1][0][0]-1+MOD)%MOD;

	//cout << "dp[1][0][1]= " << dp[1][0][1] << endl;
	//cout << "dp[1][0][0]= " << dp[1][0][0] << endl;

	cout << ans << endl;
	//system("pause");
	return 0;
}