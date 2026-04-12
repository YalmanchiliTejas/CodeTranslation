#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 200005
using namespace std;
typedef long long ll;

ll n, ans, a[N], d[N][3];
int main() {
	int i;
	memset(d, 0xc0, sizeof(d));
	cin >> n;
	for(i=1; i<=n; i++) scanf("%lld", &a[i]);
	d[1][0] = a[1];
	d[2][1] = a[2];
	d[3][0] = a[1] + a[3];
	d[3][2] = a[3];
	for(i=4; i<=n; i++) {
		d[i][0] = d[i-2][0] + a[i];
		d[i][1] = max(d[i-3][0], d[i-2][1]) + a[i];
		d[i][2] = max({d[i-4][0], d[i-3][1], d[i-2][2]}) + a[i];
	}
	if(n&1) cout << max({d[n-2][0], d[n-1][1], d[n][2]});
	else cout << max(d[n-1][0], d[n][1]);
	return 0;
}