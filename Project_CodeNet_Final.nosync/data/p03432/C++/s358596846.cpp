#include<cstdio>
#include<algorithm>
#define N_ 8192
#define M_ 210
using namespace std;


struct NTT {
	const int A = 119, B = 23, P = A << B | 1, R = 3;
	const int SZ = 14, N = 1 << SZ;

	int Pow(int x, int y) {
		int r = 1;
		while (y) {
			if (y & 1) r = (long long)r * x % P;
			x = (long long)x * x % P;
			y >>= 1;
		}
		return r;
	}

	void FFT(int *a, bool f) {
		int i, j, k, x, y, z;
		j = 0;
		for (i = 1; i < N; i++) {
			for (k = N >> 1; j >= k; k >>= 1) j -= k;
			j += k;
			if (i < j) {
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
		for (i = 1; i < N; i <<= 1) {
			x = Pow(f ? Pow(R, P - 2) : R, P / i >> 1);
			for (j = 0; j < N; j += i << 1) {
				y = 1;
				for (k = 0; k < i; k++) {
					z = (long long)a[i | j | k] * y % P;
					a[i | j | k] = a[j | k] - z;
					if (a[i | j | k] < 0) a[i | j | k] += P;
					a[j | k] += z;
					if (a[j | k] >= P) a[j | k] -= P;
					y = (long long)y * x % P;
				}
			}
		}
		if (f) {
			j = Pow(N, P - 2);
			for (i = 0; i < N; i++) a[i] = (long long)a[i] * j % P;
		}
	}
}NTT1;

int n, m, F[N_*2], InvF[N_*2], D[N_*2], C[N_ * 2], ND[N_], T[N_];
int main() {
	int i, j, k;
	scanf("%d%d", &n, &m);
	D[0] = 1;
	F[0] = 1;
	for (i = 1; i <= N_; i++)F[i] = 1ll * F[i - 1] * i%NTT1.P;
	InvF[N_] = NTT1.Pow(F[N_], NTT1.P - 2);
	for (i = N_; i >= 1; i--)InvF[i - 1] = 1ll * InvF[i] * i%NTT1.P;
	for (int i = 0; i < N_; i++)C[i] = InvF[i];
	NTT1.FFT(C, false);
	for (i = 1; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			T[j] = D[j];
			D[j] = 1ll * D[j] * InvF[j] % NTT1.P;
		}
		NTT1.FFT(D, false);
		for (j = 0; j < N_+N_; j++)D[j] = 1ll * D[j] * C[j] % NTT1.P;
		NTT1.FFT(D, true);
		for (j = 0; j <= n; j++) {
			ND[j] = (1ll * NTT1.P * 3 + 1ll * D[j + 2] * F[j + 2] % NTT1.P - T[j + 2] - 1ll * T[j + 1] * (j + 2) % NTT1.P - 1ll*j*T[j]%NTT1.P) % NTT1.P;
		}
		for (j = 0; j <= n; j++)D[j] = ND[j];
		for (j = n + 1; j < N_+N_; j++)D[j] = 0;
	}

	int res = 0;
	for (i = 0; i <= n; i++) {
		res = (res + 1ll * F[n]*InvF[i]% NTT1.P*InvF[n-i]%NTT1.P * D[i]) % NTT1.P;
	}
	printf("%d\n", res);
	return 0;
}