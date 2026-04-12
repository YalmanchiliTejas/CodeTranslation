#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	long long a, b, c, x, y, cost, ans;
	cin >> a >> b >> c >> x >> y;

	long long z = max(x, y);

	for(long long i=0; i<=z; i++){
		if(x-i>=0 && y-i>=0) cost = (x-i)*a + (y-i)*b + 2*i*c;
		if(x-i>=0 && y-i<0) cost = (x-i)*a + 2*i*c;
		if(x-i<0 && y-i>=0) cost = (y-i)*b + 2*i*c;

		if(i==0 || ans>cost) ans = cost;
	}
	cout << ans << endl;
}