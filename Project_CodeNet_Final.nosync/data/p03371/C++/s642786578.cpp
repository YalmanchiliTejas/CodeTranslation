#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	int a, b, c, x, y;
    int p, q, r, r1, r2, s;

    cin >> a >> b >> c >> x >> y;

    p = min(x, y);
    q = max(x, y);
    r = a * x + b * y;
    r1 = c * p * 2 + a * (x - p) + b * (y - p);
    r2 = c * q * 2;

    s = min(r, r1);
    s = min(s, r2);

    cout << s << endl;
	
	return 0;
}
