#include<iostream>
#include<algorithm>
#define MOD 1000000007
using namespace std;
int main()
{
	int n;
	int i, j;
	unsigned long ans;

	cin >> n;
	unsigned long *a = new unsigned long[n];
	unsigned long total = 0;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		total = (total + a[i]) % MOD;
	}

	unsigned long tmp;
	unsigned long tmp2;
	ans = 0;
	for (i = 0; i < n; i++) {
		if (a[i] > total) {
			total = MOD + total - a[i];
		}
		else {
			total = total - a[i];
		}
		tmp2 = (a[i] * total)%MOD;
		ans = ans + tmp2;
		ans = ans % MOD;
	}

	cout << ans << endl;
	return 0;
}
