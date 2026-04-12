#include <bits/stdc++.h>
using namespace std;

int main(){
	string S;
	cin >> S;
	int K, N = S.size(), i, j;
	scanf("%d", &K);
	vector<int> A(N + 1, 0);
	for(i = 1; i <= N; i++){
		A[i] = S[i - 1] - '0';
	}
	vector<vector<int>> dp_less(N + 1, vector<int>(K + 1, 0));
	vector<vector<int>> dp_eq(N + 1, vector<int>(K + 1, 0));
	dp_eq[0][0] = 1;
	for(i = 1; i <= N; i++){
		dp_less[i][0] = 1;
		dp_eq[i][0] = 0;
		for(j = 1; j <= K; j++){
			dp_less[i][j] = dp_less[i - 1][j] + 9 * dp_less[i - 1][j - 1];
			if(A[i] > 0){
				dp_less[i][j] += dp_eq[i - 1][j] + (A[i] - 1) * dp_eq[i - 1][j - 1];
			}
			if(A[i] == 0){
				dp_eq[i][j] = dp_eq[i - 1][j];
			}
			else{
				dp_eq[i][j] = dp_eq[i - 1][j - 1];
			}
		}
	}
	printf("%d\n", dp_less[N][K] + dp_eq[N][K]);
	return 0;
}