#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	long long int N, K;
	cin >> N >> K;
	if(K == 0){
		cout << N * N << endl;
		return 0;
	}
	long long int ans = 0;
	for(int i = K + 1; i <= N; i++){
		ans += N / i * (i - K) + max(0LL, N % i - K + 1);
	}
	cout << ans << endl;
	return 0;
}
