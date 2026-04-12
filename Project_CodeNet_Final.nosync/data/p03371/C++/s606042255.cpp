#include<iostream>
#include<cmath>
using namespace std; 

int main(){
	int a, b, c, x, y;
	long long sum;
	cin>>a>>b>>c>>x>>y;
	
	if((a+b) >= c*2){		//若两盒c比1a1b便宜 
		if(x >= y)				//部分ab部分c 
			sum = min(x, y)*c*2 + abs(x-y)*a;
		else if(x < y)
			sum = min(x, y)*c*2 + abs(x-y)*b;
		
		if(sum > max(x, y)*c*2)	//全买c 
			sum = max(x, y)*c*2; 
	}
	else{					//若两盒c比1a1b贵
		sum = a*x + b*y;
	}
	cout<<sum;
	return 0;
}