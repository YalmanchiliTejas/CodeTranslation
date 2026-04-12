#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>

using namespace std;

int main() {
	int n;
	
	cin >> n;

	vector<long long> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];	
	}

	vector<long long> sum(n+1);
	sum[0] = 0;

	for (int i = 0; i < n; i++) {
		sum[i + 1] = (sum[i] + arr[i])%1000000007;
	}
	
	long long ans = 0;
	
	for (int i = 0; i < n-1;i++) {
			ans += ((arr[i] % 1000000007) * (sum[n]-sum[i+1])) % 1000000007;
			ans = ans % 1000000007;
	}

	if (ans < 0)ans=ans + 1000000007;

	cout << ans << endl;

	return 0;
}