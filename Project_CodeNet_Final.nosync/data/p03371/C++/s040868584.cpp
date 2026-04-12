#include<bits/stdc++.h>
using namespace std;


int main() {
	
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	
	int sum = a*x + b*y;
	for(int i=0; i<=2*max(x,y); i+=2){
		sum = min( i*c + max(0, a*(x-i/2)) + max(0, b*(y-i/2)) , sum);
	}
	cout << sum <<endl;
	
	
	return 0;
}