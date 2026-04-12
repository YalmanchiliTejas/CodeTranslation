#include<iostream>

using namespace std;

int main(void){
	
	int r,g,b;
	int sum=0;
	
	cin>>r>>g>>b;
	
	sum=r*100+g*10+b;
	
	if(sum%4==0)
			puts("YES");
	else
			puts("NO");
	
	
	
	return 0;
}
