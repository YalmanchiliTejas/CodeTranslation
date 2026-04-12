#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
#define rep(i,n) for(i=0;i<n;i++)
#define repl(k,n) for(k=0;k<n;++k)

int main() {
	int N;
	cin >> N;
	vector<long long int>A(N);
	int i;
	long long int sum1=0;
	long long int sum2=0;
	long long int ans = 0;
	long long int sum;
	rep(i, N) {
		cin >> A[i];
		sum1 =sum1+ A[i];
		sum = A[i] * A[i];
		sum = sum % 1000000007;
		sum2 =sum2+ sum;
	}
	sum1 = sum1 % 1000000007;
	sum2 = sum2 % 1000000007;
	sum1 = (sum1 * sum1) % 1000000007;
	if (sum1 < sum2) {
		sum1 = sum1 + 1000000007;
	}
	ans = (sum1 - sum2) % 1000000007;
	if (ans % 2 != 0) {
		ans = ans + 1000000007;
	}
	ans = ans / 2;
	cout << ans;
	return 0;
}