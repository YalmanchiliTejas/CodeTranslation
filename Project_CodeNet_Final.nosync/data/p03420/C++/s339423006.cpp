#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	int N, K;
	long long ans = 0;
	cin >> N >> K;
	if (K == 0) {
		cout << 1LL * N*N << '\n';
		return 0;
	}
	for (int i = K + 1; i <= N; i++) {
		ans += 1LL * (N / i)*(i - K) + max(N%i - K + 1, 0);
	}
	cout << ans << '\n';
	return 0;
}