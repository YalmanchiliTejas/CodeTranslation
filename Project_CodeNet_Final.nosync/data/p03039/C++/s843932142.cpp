#include <iostream>
#include <algorithm>
using namespace std;

long long int N, M, K;

long long int MOD = 1000000007;

long long int num = 1;

long long int POW(long long int K, long long int p) {

	if (p == 0) { return 1; }
	else if (p == 1) { return K; }

	if ((p % 2) == 1) { return (K*POW(K, p - 1)) %MOD; }

	long long int tmp = POW(K, p / 2);

	return (tmp*tmp)%MOD;

}

int main(void) {

	cin >> N >> M >> K;

	
	for (int i = 0; i < K - 2; i++) {
		//cout << "num= " << num << endl;
		num *= (N*M - 2 - i);
		num %= MOD;
		//cout << POW(K - 2 - i, MOD - 2) << endl;
		num *= POW(K - 2 - i, MOD - 2);
		num %= MOD;
	}

	

	long long int ans = 0;

	if (K <= 1) {cout << 0 << endl; return 0;}

	for (long long int i = 1; i <= N + M - 2; i++) {

		long long int MA = min(N, i + 1);
		long long int m = max((long long int) 1,(long long int) 2+i - M);
		long long int tmp = 0;

		tmp =( (N + 1)*(M-i-1) %MOD) *(MA - m + 1) + (N - M + i+2)*(((MA*(MA + 1)) / 2 - ((m - 1)*m) / 2) %MOD) +MOD - (( ((MA*(MA + 1) %MOD) *(MA * 2 + 1)) %MOD)*POW(6,MOD-2) %MOD) + ((((m - 1)*m %MOD)*(m * 2 - 1)) %MOD) *POW( 6,MOD-2);
	
		if (M > i) { tmp -= (M - i)*N; }
		if (N > i) { tmp -= (N - i)*M; }
		
		tmp *= 2;
		if (M > i) { tmp += (M - i)*N; }
		if (N > i) { tmp += (N - i)*M; }

		tmp %= MOD;

		//cout << "i= " << i << " tmp= " << tmp << endl;
		ans += ((num*i)%MOD)*tmp;
			ans %= MOD;
	}

	cout << ans << endl;

	return 0;
}