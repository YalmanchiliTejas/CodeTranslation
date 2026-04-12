#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>());
	if(n % 2 == 0) {
		long long res = 0;
		for (int i = 0; i < n/2-1; i++)
		{
			res += a[i] * 2;
		}
		res += a[n/2-1] - a[n/2];
		for (int i = n/2+1; i < n; i++)
		{
			res -= a[i] * 2;
		}
		cout << res << endl;
	}
	else {
		long long res1 = 0, res2 = 0;
		for (int i = 0; i < n/2-1; i++)
		{
			res1 += a[i] * 2;
		}
		res1 += a[n/2-1] + a[n/2];
		for (int i = n/2+1; i < n; i++)
		{
			res1 -= a[i] * 2;
		}
		for (int i = 0; i < n/2; i++)
		{
			res2 += a[i] * 2;
		}
		res2 -= a[n/2] + a[n/2+1];
		for (int i = n/2+2; i < n; i++)
		{
			res2 -= a[i] * 2;
		}
		cout << max(res1, res2) << endl;
	}
	return 0;
}
