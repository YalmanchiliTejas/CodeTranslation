#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	long long combined = min(x,y);
	long long sum=0;
	sum+= min(2*combined*c,combined*(a+b));
	if (x>y) {
		sum+=min((x-y)*a,2*(x-y)*c);
	}
	else{
		sum+=min((y-x)*b,2*(y-x)*c);
	}
	cout << sum;
	
 }
