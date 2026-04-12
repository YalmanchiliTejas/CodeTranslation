#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdint>
#include <cmath>
#include <algorithm>
using namespace std;

#define N 100001

int sum[N];

int main()
{
	int a, b, c;
	int x, y;
	int ans;

	cin >> a >> b >> c >> x >> y;

	int n = x;
	if( y > n ) {
		n = y;
	}

	for( int i = 0; i <= n; i++ ) {
		int xx = x - i;
		if( xx < 0 ) {
			xx = 0;
		}
		int yy = y - i;
		if( yy < 0 ) {
			yy = 0;
		}
		sum[i] = a*xx + b*yy + c*i*2;
	}

	sort(sum, sum + n+1);
	ans = sum[0];

	cout << ans << endl;

	return 0;
}
