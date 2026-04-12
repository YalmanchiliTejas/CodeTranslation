#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0); ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int t;cin>>t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	
	int l = 1, r = n-2;
	ll cl = a[0], cr = a[n-1];
	ll sum = cr - cl;

	while (l <= r) {
		if (cl > cr)
			swap(cl, cr);
	
		if (abs(cl - a[r]) < abs(cr - a[l])) {
			sum += abs(cr- a[l]);
			cr = a[l];
			l++;
		} else {
			sum += abs(cl - a[r]);
			cl = a[r];
			r--;
		}
	}

	cout << sum << endl;

	return 0;
}

