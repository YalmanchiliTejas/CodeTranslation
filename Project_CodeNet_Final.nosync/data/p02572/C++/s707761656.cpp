#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<unsigned long long> a(n);
	rep(i, n)
		cin >> a[i];
	unsigned long long ans = 0;
	unsigned long long sumofA = 0;
	rep(i, n-1) {
		sumofA += a[i];
		ans += (sumofA % (1000000007)) * a[i + 1];
		ans = ans % (1000000007);
	}
	cout << ans << endl;
	return 0;
}