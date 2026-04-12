#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 10005;

void add(int &a, int b) { a += b; if(MOD <= a) a -= MOD; }

int dp[MAXN][100], S[MAXN];

int B[MAXN];
char A[MAXN];

int N, D, Ans;

int main() {
	scanf(" %s%d", A+1, &D);
	N = int(strlen(A+1));
	for(int i = 1; i <= N; i++) {
		B[i] = A[i] & 15;
		S[i] = S[i-1] + B[i];
	}

	for(int i = 1; i <= N; i++) {
		for(int j = D; j--;)
			for(int k = 10; k--;)
				add(dp[i][(j+k)%D], dp[i-1][j]);
		for(int j = B[i]; j--;)
			add(dp[i][(S[i-1]+j)%D], 1);
	}

	Ans = dp[N][0];
	add(Ans, MOD-1);
	if(!(S[N] % D)) add(Ans, 1);

	cout << Ans << endl;
	return 0;
}