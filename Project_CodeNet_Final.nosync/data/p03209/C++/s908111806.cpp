#include <bits/stdc++.h>
using namespace std;
vector<long long> la(51,1),pa(51,1);
long long ans = 0;

void check(int n, long long x) {
	if (n > 0) {
		if (x == la[n] || x == la[n] - 1) {
			ans += pa[n];
			x = 0;
		}
		else if (la[n] / 2 + 1 < x&&x < la[n] - 1) {
			ans += pa[n - 1]+1;
			x -= la[n] / 2 + 1;
		}
		else if (x == la[n]/2 + 1) {
			ans += 1;
			x -= 2;
		}
		else if (x == 0 || x == 1)
			x = 0;
		else
			x--;
		check(n - 1, x);
	}
	else
		ans += x;
}

int main() {
	long long n, x;
	cin >> n >> x;
	for (int i = 1;i < n+1;i++) {
		pa[i] = pa[i - 1] * 2 + 1;
		la[i] = la[i - 1] * 2 + 3;
	}
	check(n, x);
	cout << ans << endl;
	//for (int i = 0;i < 50;i++)
		//cout << la[i] << " " << pa[i] << endl;
}