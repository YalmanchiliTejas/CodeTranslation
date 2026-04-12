#include <iostream>
#include <algorithm>

using namespace std;
int N;
long long int a[3030];

long long int dp[3030][3030];

int main(void) {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}

	if (N % 2 == 0) {
		for (int i = 1; i <= N; i++) { dp[i][i] = -a[i]; }
	}
	else {
		for (int i = 1; i <= N; i++) { dp[i][i] = a[i]; }
	}

	for (int k = 2; k <= N; k++) {
		for (int i = 1; i <= N - k + 1; i++) {
			int j = i + k - 1;
			int sign; // +1: Taro, -1: Jiro
			if ((N % 2 == 0) && (k % 2 == 0)) { sign = 1; }
			else if ((N % 2 == 1) && (k % 2 == 1)) { sign = 1; }
			else { sign = -1; }

			if (sign == 1) { //Taro
				dp[i][j] = max(a[i] + dp[i + 1][j], dp[i][j - 1] + a[j]);
			}
			else {//Jiro
				dp[i][j] = min(-a[i] + dp[i + 1][j], dp[i][j - 1] - a[j]);
			}
		}
	}

	cout << dp[1][N] << endl;

	//system("pause");
	return 0;
}