#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int main()
{
	int a, b, c, x, y;
	int ans = 0, ndadd;
	cin >> a >> b >> c >> x >> y;
	if(a + b <= 2*c){
		ans += x*a + y*b;
	}
	else{
		int ab = min(x, y);
		ans += 2*ab*c;
		int rst = max(x, y) - ab;
		int rstnd = 2*rst*c;
		if(x>y) ndadd = min(rstnd, rst*a);
		else ndadd = min(rstnd, rst*b);
		ans += ndadd;
	}
	cout << ans << endl;
	return 0;
}