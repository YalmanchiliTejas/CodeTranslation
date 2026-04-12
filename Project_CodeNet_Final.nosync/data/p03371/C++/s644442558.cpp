#include <iostream>
#include <math.h>

using namespace std;

int main(){
	long long a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;

	long long pt1 = x*a+b*y;
	long long pt2 = c * max(x,y) * 2;
	long long pt3 = 0;
	if(x < y){
		pt3 = c * x * 2;
		pt3 += b * (y-x);
	}else{
		pt3 = c * y * 2;
		pt3 += a * (x-y);
	}

	cout << min(pt1,min(pt2,pt3)) << endl;

	return 0;
}