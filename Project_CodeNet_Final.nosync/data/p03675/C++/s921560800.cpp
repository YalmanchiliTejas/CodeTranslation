#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
int a[200000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n % 2 == 0) {
		for (int i = n - 1; i >= 1; i -= 2) {
			cout << a[i] << " ";
		}
		for (int i = 0; i <= n - 2; i += 2) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = n - 1; i >= 0; i -= 2) {
			cout << a[i] << " ";
		}
		for (int i = 1; i <= n - 2; i += 2) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
 }