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
	int n, X, x[200000],y[200000];
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> X; x[i] = X; y[i] = X;
	}
	sort(x, x + n); int c = x[n / 2-1];
	for (i = 0; i < n; i++) {
		if (y[i] <= c)cout << x[n / 2] << endl;
		else cout << c << endl;
	}
	return 0;
}
