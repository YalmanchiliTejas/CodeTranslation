#include <iostream>
#include <vector>
using namespace std;

using cat = unsigned long long;

constexpr cat mod = 998244353;

cat pw(int a, int e) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2);
	x = x * x % mod;
	if(e%2) x = x * a % mod;
	return x;
}

inline __attribute__((always_inline)) void add(const cat * __restrict A, cat * __restrict res, int L) {
	for(int i = 0; i < L; i++) {
		res[i] += A[i];
		if(res[i] >= mod) res[i] -= mod;
	}
}

inline __attribute__((always_inline)) void sub(const cat * __restrict A, cat * __restrict res, int L) {
	for(int i = 0; i < L; i++) {
		res[i] += mod-A[i];
		if(res[i] >= mod) res[i] -= mod;
	}
}

void karatsuba(const cat * __restrict A, const cat * __restrict B, cat * __restrict res, int L) {
	if(L <= 32) {
		for(int i = 0; i < L; i++) for(int j = 0; j < L; j++) {
			res[i+j] += A[i] * B[j];
			constexpr cat mod2 = 8 * mod * mod;
			if(res[i+j] >= mod2) res[i+j] -= mod2;
		}
		for(int i = 0; i <= 2*L-2; i++) res[i] %= mod;
		return;
	}
	vector<cat> prod_low(2*(L/2)-1, 0), prod_high(2*(L-L/2)-1, 0);
	karatsuba(A, B, &(prod_low[0]), L/2);
	karatsuba(A+L/2, B+L/2, &(prod_high[0]), L-L/2);
	vector<cat> A_comb(L-L/2, 0), B_comb(L-L/2, 0);
	for(int i = 0; i < L/2; i++) {
		A_comb[i] = A[i] + A[i+L/2];
		if(A_comb[i] >= mod) A_comb[i] -= mod;
	}
	for(int i = 0; i < L/2; i++) {
		B_comb[i] = B[i] + B[i+L/2];
		if(B_comb[i] >= mod) B_comb[i] -= mod;
	}
	if(L%2) A_comb[L/2] = A[L-1], B_comb[L/2] = B[L-1];
	vector<cat> res_comb(2*(L-L/2)-1, 0);
	karatsuba(A_comb.data(), B_comb.data(), &(res_comb[0]), L-L/2);
	add(prod_low.data(), res, 2*(L/2)-1);
	add(prod_high.data(), res+2*(L/2), 2*(L-L/2)-1);
	sub(prod_low.data(), &(res_comb[0]), 2*(L/2)-1);
	sub(prod_high.data(), &(res_comb[0]), 2*(L-L/2)-1);
	add(res_comb.data(), res+L/2, 2*(L-L/2)-1);
}

vector<cat> multiply(vector<cat> & A, vector<cat> & B) {
	int N = A.size();
	vector<cat> ret(2*N-1, 0);
	karatsuba(A.data(), B.data(), &(ret[0]), N);
	return ret;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<cat> F(N+3, 1), FI(N+3, 1);
	for(int i = 1; i < N+3; i++) F[i] = F[i-1] * i % mod;
	for(int i = 1; i < N+3; i++) FI[i] = FI[i-1] * pw(i, mod-2) % mod;
	vector< vector<cat> > dp(M+1, vector<cat>(N+3, 0));
	dp[0][0] = 1;
	for(int i = 1; i <= M; i++) {
		static vector<cat> FI_mul = FI;
		FI_mul[0] = FI_mul[1] = FI_mul[2] = FI_mul[3] = 0;
		for(int j = 0; j <= N; j++) dp[i-1][j] = dp[i-1][j] * FI[j] % mod;
		vector<cat> prod = multiply(FI_mul, dp[i-1]);
		for(int j = 0; j <= N; j++) dp[i-1][j] = dp[i-1][j] * F[j] % mod;
		for(int j = 0; j <= N; j++) {
			dp[i][j] = prod[j+2] * F[j+2] % mod;
			if(j > 0)
				dp[i][j] = (dp[i][j] + (1LL*j*(j+1)*(j+2)/6) % mod * dp[i-1][j-1]) % mod;
			dp[i][j] = (dp[i][j] + ((j+1)*j/2+1) * dp[i-1][j]) % mod;
		}
	}
	cat ans = 0;
	for(int i = 0; i <= N; i++) ans = (ans + F[N] * FI[N-i] % mod * FI[i] % mod * dp[M][i]) % mod;
	cout << ans << "\n";
}
