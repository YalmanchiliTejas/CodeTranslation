#include<bits/stdc++.h>
using namespace std;

int lcm( int m, int n ){
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	return ((m / __gcd(m, n)) * n);
}

int main() {
	int a,b,x;
	double d,d2;
	cin >> a >> b;
	x = lcm(a,b);
	d = x/a + x/b;
	d2= x;
	printf("%.10lf\n", d2/d);
	return 0;
}
 