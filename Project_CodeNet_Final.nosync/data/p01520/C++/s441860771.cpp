#include<iostream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n, t, e;
	cin >> n >> t >> e;
	int a[100];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k1 = t - e, k2 = t + e;
	for (int i = 0; i < n; i++) {
		int c = t%a[i];
		int t2 = t - c;
		if (t2 >= k1&&t2 <= k2) {
			cout << i + 1 << endl;
			goto stop;
		}
		t2 += a[i];
		if (t2 >= k1&&t2 <= k2) {
			cout << i+1 << endl;
			goto stop;
		}
	}
	cout << -1 << endl;
stop:;
}