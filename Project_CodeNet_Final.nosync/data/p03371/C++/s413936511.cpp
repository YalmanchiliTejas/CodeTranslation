#include <iostream>
#include <cstdio>
using namespace std;
int a, b, c, x, y, s, mn;
int main() {
	cin>>a>>b>>c>>x>>y;
	mn = s = a*x + b*y;
	for(int i=1; i<=max(x, y); i++) {
		if(i<=min(x, y)) s -= a + b;
		else {
			if(x>y) s -= a;
			else s -= b;
		}
		s += c*2;
		mn = min(mn, s);
	}
	cout<<mn;
	return 0;
}