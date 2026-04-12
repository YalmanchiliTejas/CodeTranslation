#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int N, s[100001];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}

	long long ans = 0;
	for (int c = 1; c < N; c++) {
		long long sum = 0;
		for (int k = 0; (k + 1) * c < N - 1; k++) {
			if (k * c >= N - 1 - k * c && (N - 1) % c == 0) {
				break;
			}
			sum += s[(N - 1) - k * c] + s[k * c];
			ans = max(ans, sum);
		}
	}

	cout << ans << "\n";

	return 0;
}
