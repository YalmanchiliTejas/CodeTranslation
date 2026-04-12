//ABC115 D
#include<iostream>
#include<math.h>
using namespace std;
int n;
long long x, ans;
long long p[51];
long long all[51];
void saiki(int l);
int main() {
	cin >> n >> x;
	p[0] = 1;
	all[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] * 2 + 1;
		all[i] = all[i - 1] * 2 + 3;
	}
	ans = 0;
	saiki(n);
	cout << ans << endl;
	return(0);
}
void saiki(int l) {
	if (x <= l) {
		ans += 0;
	}
	else if (x <= all[l - 1] + 1) {
		x -= 1;
		saiki(l-1);
	}
	else if (x <= all[l-1]*2 +2) {
		ans += p[l - 1] + 1;
		x -= all[l - 1] + 2;
		saiki(l - 1);
	}
	else{
		ans += p[l];
	}
}