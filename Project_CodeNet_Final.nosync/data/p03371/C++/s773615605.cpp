#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <map>
#define ll long long
const int MOD = 1e9+7;
using namespace std;


int main(){
	int a, b, c, x, y;
	ll ans = 0;
	cin >> a >> b >> c >> x >> y;
	if (a + b >= c*2){
		ans += c*2*min(x, y);
		if (x > y){
			if (c*2 < a) ans += c*2*(x-y);
			else ans += a*(x-y);
		}else{
			if (c*2 < b) ans += c*2*(y-x);
			else ans += b*(y-x);
		}
		cout << ans << endl;
	}else{
		cout << a*x + b*y << endl;
	}
	return 0;
}