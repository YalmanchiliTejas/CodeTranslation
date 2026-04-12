#include<iostream>
#include <string>
#include<algorithm>
#include <set>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int N,i;
	long sum;
	cin >> N;
	int a[N];
	for (i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N, greater<int>());
	sum = 0;
	if (N % 2 == 0) {
		sum += a[0] - a[N - 1];
		for (i = 0; i < N / 2 - 1; i++) {
			sum += a[i] + a[i + 1] - a[N - i - 1] - a[N - i - 2];
		}
	}
	else {
		sum += a[0] - a[N - 1];
		for (i = 0; i < N / 2 - 1; i++) {
			sum += a[i] + a[i + 1] - a[N - i - 1] - a[N - i - 2];
		}
		if (a[(N - 1) / 2] - a[(N + 1) / 2] > a[(N - 3) / 2] - a[(N - 1) / 2]) {
			sum += a[(N - 1) / 2] - a[(N + 1) / 2];
		}
		else {
			sum += a[(N - 3) / 2] - a[(N - 1) / 2];
		}
	}
	cout << sum;
	return 0;
}
