#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	long long int N, K;
	cin >> N >> K;

	long long int ans = 0;
	for (size_t i = K + 1; i <= N; i++)
	{
		if (K == 0)
		{
			ans += N;
			continue;
		}
		long long int b = i;
		long long int a = (b - K)*(N / b) + max((long long int)0, (N%b - K + 1));
		ans += a;
	}

	cout << ans;

	return 0;
}