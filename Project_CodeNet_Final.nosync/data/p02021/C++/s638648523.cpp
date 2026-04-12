#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define P pair<int,int>
#define vsort(v) sort(v.begin(),v.end)
using namespace std;
signed main() {
	int n, a[100], m = 0;
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		m += a[i];
	}
	m /= n;
	for (int i = m; i >= 0; i--) {
		int cnt = 0;
		rep(j, n) {
			cnt += a[j];
			cnt -= i;
			if (cnt < 0)goto ioi;
		}
		cout << i << endl;
		return 0;
	ioi:;
	}
}
