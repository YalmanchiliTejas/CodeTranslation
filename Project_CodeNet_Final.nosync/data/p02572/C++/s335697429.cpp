#include<iostream>
#include<variant>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<climits>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	int sum = 0;
	long long int tot = 0;
	vector<long long int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum = (sum + a[i]) % 1000000007;
	}
	for (int i = 0; i < n; i++) {
		sum = (1000000007 + sum - a[i]) % 1000000007;
		tot = (tot + a[i] * sum) % 1000000007;
	}
	cout << tot;
	return 0;
}