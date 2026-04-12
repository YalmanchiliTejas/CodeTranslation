#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int a,b,c,x,y;
	
	cin >> a >> b >> c >> x >> y;
	
	int en1,en2,en3;
	
	en1 = a*x+b*y;
	
	en2 = max(x,y)*2*c;
	
	if(x>y)
		en3 = 2*c*y + (x-y)*a;
	else
		en3 = 2*c*x + (y-x)*b;
	
	cout << min({en1,en2,en3}) ;
	
	return 0;
}