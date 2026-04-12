#include"bits/stdc++.h"
#define int long long
using namespace std;
const int mod = 1000000007;
int a[100006];
class BIT {
	public:
		int bit[100006];
		int N;

	void init(int n) {
		N = n;
		for(int i=0;i< n;i++)bit[i] = 0;
	}
	int sum(int i) {
		int s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i&-i;
		}
		return s;
	}
	void add(int i, int x) {
		while (i <= N) {
			bit[i] += x;
			i += i&-i;
		}
	}
};

BIT bit;

signed main() {
	int n; cin >> n;
	for(int i=0;i<n;i++)cin >> a[i];
	map<int, int>M1,M2;
	for (int i = 0; i < n; i++)M1[a[i]]++;
	int cnt = 1;
	for (auto itr = M1.begin(); itr != M1.end(); itr++) {
		M2[itr->first] = cnt;
		cnt++;
	}
	for (int i = 0; i < n; i++) {
		a[i] = M2[a[i]];
	}
	bit.init(n);
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int S = bit.sum(a[i]-1);
		if (S == 0) {
			ans++;
			bit.add(a[i], 1);
		}
		else {
			int lb = 0, ub = a[i];
			while (ub - lb > 1) {
				int mi = (ub + lb) / 2;
				if (S == bit.sum(mi)) {
					ub = mi;
				}
				else lb = mi;
			}
//			cout << ub << endl;
			bit.add(ub, -1);
			bit.add(a[i], 1);
		}
	}
	cout << ans << endl;
}