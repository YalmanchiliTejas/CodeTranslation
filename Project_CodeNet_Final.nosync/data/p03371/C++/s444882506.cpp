#include<iostream>
using namespace std;

int main(){
	int a, b, c, x, y, sum;
	cin >> a >> b >> c >> x >> y;
	sum = a * x + b * y;
	if(sum > max(x, y) * c * 2) sum = max(x, y) * c * 2;
	if(x > y) {
		if((x-y)*a + y *c * 2 < sum) sum = (x-y) * a + y * c * 2;
	}else{
		if((y-x)*b + x *c * 2 < sum) sum = (y-x)* b + x * c * 2;
	}
	cout << sum;
	return 0;
}
