#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string>

using namespace std;

int main() {
	long long N, K;
	cin >> N >> K;
	long long ans = 0;
	if (K == 0) {
		cout << N * N << endl;
		system("pause");
		return 0;
	}
	for (int b = 1; b <= N; b++) {
		long long M = N % b;
		long long Q = N / b;
		if(b > K) ans += Q * (b - K);
		if (M >= K) ans += M - K + 1;
	}
	cout << ans << endl;
	system("pause");
	return 0;
}