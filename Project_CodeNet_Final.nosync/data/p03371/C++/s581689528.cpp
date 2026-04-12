#include <bits/stdc++.h>
using namespace std;

int main(void){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int res = (int) 1e9;
	for(int i = 0; i <= 2 * max(x, y); i+=2){
		int p = c*i;
		if(x-i/2 >= 0) p += a*(x-i/2);
		if(y-i/2 >= 0) p += b*(y-i/2);
		res = min(res, p);
	}

	cout << res << endl;
}