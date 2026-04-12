#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, a, k, x, d[100005];
int main() {
	cin >> n;
	while(n--) {
		scanf("%d", &a);
		x = upper_bound(d, d+k, a, greater<int>()) - d;
		d[x] = a;
		if(x==k) ++k;
	}
	cout << k;
	return 0;
}