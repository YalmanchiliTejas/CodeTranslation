#include <iostream>
using namespace std;
 
int main() {
	int n;
	while(1){
	cin >> n;
	if(n==0)break;
	int min,max;
	int s,x;
	cin >>s;
	min=s;
	max=s;
	x=s;
		for(int i=0;i<n-1;i++){
		cin >>s;
		x=x+s;
		if(min >s) min=s;
		if(max <s) max=s;
 
		}
	x=x-max-min;
    x=x/(n-2);
	cout << x <<endl;
	}
	return 0;
}