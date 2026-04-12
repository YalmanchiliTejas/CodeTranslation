#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui;
int main() {
	int n, k,i;
	cin >> n >> k;
	ll sum = 0;
	for (i = k + 1; i <= n; i++) {
		sum += (ll)((n / i)*(i - k));
		int l = n%i;
		if (l >= k) {
			sum += (ll)(l - k + 1);
		}
		if (k == 0)sum--;
	}
	cout << sum << endl;
	char nyaa;
	cin >> nyaa;
	return 0;
}
