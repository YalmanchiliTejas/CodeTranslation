#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
using namespace std;

int main() {
	map<long long int, long long int>mp;
	//cout << fixed << setprecision(10);
	long long int n,m,a[200005],b, k, sum = 0, d, w, h;
	long long dp[200005] = {}, memo[200005] = {};
	string str,str2;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n % 2 == 0) {
		for (int i = 1; i < n / 2; i++) {
			sum -= 2 * a[i];
		}
		for (int i = n / 2 + 2; i <= n; i++) {
			sum += 2 * a[i];
		}
		sum += a[n / 2 + 1] - a[n / 2];
	}
	else {
		for (int i = 1; i < n / 2; i++) {
			sum -= 2 * a[i];
		}
		for (int i = n / 2 + 3; i <= n; i++) {
			sum += 2 * a[i];
		}
		sum += max(2 * a[n / 2 + 2] - a[n / 2 + 1] - a[n / 2], a[n / 2 + 2] + a[n / 2 + 1] - 2 * a[n / 2]);
	}
	cout << sum;
}
