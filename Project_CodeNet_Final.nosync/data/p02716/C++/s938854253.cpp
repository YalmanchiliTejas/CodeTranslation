// ABC162A.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include <iostream>

void solve_A() {
	int N; std::cin >> N;
	int mod_1 = N % 10;
	N /= 10;
	int mod_2 = N % 10;
	N /= 10;
	int mod_3 = N % 10;
	N /= 10;
	if (mod_1 == 7 || mod_2 == 7 || mod_3 == 7) {
		std::cout << "Yes";
	}
	else {
		std::cout << "No";
	}

}

void solve_B() {
	int N;
	std::cin >> N;

	long long int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (i % 3 != 0 && i % 5 != 0) {
			sum += i;
		}
	}
	std::cout << sum;
}

int gcd(int y, int x) {
	if (y < x) std::swap(x, y);
	int r;
	while (x > 0) {
		r = y % x;
		y = x;
		x = r;
	}

	return y;

}

void solve_C(){
	int K;
	std::cin >> K;

	int sum = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= K; j++) {
			for (int k = 1; k <= K; k++) {
				sum += gcd(gcd(i, j), k);
			}
		}
	}

	std::cout << sum;

}

#include <string>
void solve_D() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	long long r_count = 0, g_count = 0, b_count = 0;
	for(int i = 0; i < n;i++) {
		if (s[i] == 'R') r_count++;
		else if (s[i] == 'G') g_count++;
		else b_count++;
	}
	long long ans = r_count * g_count * b_count;
	for (int distance = 1; distance < n + 1; distance++) {
		for (int j = 0; j + 2 * distance < n; ++j) { 
			if (s[j] != s[j + distance] && s[j + distance] != s[j + 2 * distance] && s[j] != s[j + 2 * distance])
				ans -= 1;
		}
	}
	std::cout << ans << std::endl;
}

const long long MOD = 1e9 + 7;
long long pwr(long long a, long long n) {
	a %= MOD;
	long long r = 1;
	for (; n > 0; n >>= 1) {
		if (n & 1) r = r * a % MOD;
		a = a * a % MOD;
	}
	return r;
}

void solve_E() {
	int n, k; std::cin >> n >> k;
	long long  answer = 0;
	const int N = 1e5 + 10;
	long long ways[N];
	for (int x = k; x >= 1; x--) {
		int m = k / x;
		ways[x] = pwr(m, n);
		for (int gg = 2 * x; gg <= k; gg += x) {
			ways[x] -= ways[gg];
		}
		ways[x] %= MOD;
		ways[x] += MOD;
		ways[x] %= MOD;

		answer += (ways[x] * x) % MOD;
	}
	answer %= MOD;
	std::cout << answer << std::endl;
}

#include<algorithm>
void solve_F() {
	int n;
	long long A[200001], dp[200001], sum[200001];
	//long long A[100], dp[100], sum[100];
	std::cin >> n;
	dp[0] = dp[1] = 0;
	sum[0] = sum[1] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> A[i];
		if(i==1){
			sum[i] = A[i];
			continue;
		}
		sum[i] = sum[i - 2] + A[i];
	}

	for (int i = 2; i <= n; i++) {
		if (i%2==0) {
			dp[i] = std::max(dp[i - 2] + A[i], sum[i-1]);
		}
		else if (i%2 == 1) {
			dp[i] = std::max(dp[i - 2] + A[i], dp[i-1]);
		}
	}

	std::cout << dp[n] << std::endl;

}


int main()
{
	std::ios::sync_with_stdio(false);
	//solve_A();
	//solve_B();
	//solve_C();
	//solve_D();
	//solve_E();
	solve_F();
    return 0;
}

