#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
#define mod 1000000007
using namespace std;
vector<int>v;
int n, a[123456];
signed main() {
	cin >> n; for (int i = 0; i < n; i++)cin >> a[i];
	v.push_back(a[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		if (v[v.size() - 1] <= a[i]) {
			v.push_back(a[i]);
		}
		else {
			auto ir = upper_bound(v.begin(), v.end(), a[i]);
			v.erase(ir); v.insert(ir, a[i]);
		}
	}
	cout << v.size() << endl;
}