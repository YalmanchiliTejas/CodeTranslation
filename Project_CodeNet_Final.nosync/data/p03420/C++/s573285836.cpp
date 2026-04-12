#include<iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	long long sum = 0;
	for(int b=k+1;b<=n;b++) {
		sum += (n / b) * (b - k);
		if(n % b >= k) sum += n % b - k + 1;
	}
	if(k == 0) sum -= n;
	cout << sum << endl;
	return 0;
}
