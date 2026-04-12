#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll dp[3005];

int main()
{
	ll n;
	cin >> n;
	vector<ll> num(n);
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i; j >= 0; --j) {
		    if (j == i) {
		    	dp[j] = num[i];
		    } else {
		    	dp[j] = max(num[i] - dp[j], num[j] - dp[j + 1]);
		    }
		}
	}
	cout << dp[0] << endl;
	return 0;
}
