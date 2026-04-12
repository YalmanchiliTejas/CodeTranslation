#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define mod 1000000007;

int main() {
	// your code goes here
	int a,b,c,x,y,i,min=mod;
	cin >> a >> b >> c >> x >> y;
	for(i=0;i<=std::max(x,y);i++){
		int cost=c*2*i+a*std::max(x-i,0)+b*std::max(y-i,0);
		if(min>cost) min=cost;
	}
	cout << min << endl;
	return 0;
}