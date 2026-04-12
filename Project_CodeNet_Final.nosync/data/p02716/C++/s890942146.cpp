#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	long long a[201010];
	for (int i=0; i<n; i++) cin >> a[i+1];

	long long max_ch[201010], ht[201010];
	max_ch[1] = a[1];
	ht[1] = a[1];
	max_ch[2] = max(a[2], a[1]);
	max_ch[3] = max(max_ch[2], a[3]);
	ht[3] = a[1] + a[3];
	for (int i=4; i<=n; i++) {
		long long r1 = max_ch[i-2] + a[i];
		long long r2;
		if (i%2) r2 = max_ch[i-3] + a[i-1];
		else {
			r2 = ht[i-3] + a[i-1];
			ht[i-1] = r2;
		}
		max_ch[i] = max(r1, r2);
		//cout << i << ": " << max_ch[i] << " " << a[i] << endl;
	}

	cout << max_ch[n] << endl;
}
