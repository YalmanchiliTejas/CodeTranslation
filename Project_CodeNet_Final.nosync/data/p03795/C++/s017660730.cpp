#include <iostream>
#include <stdio.h> 
using namespace std;
int main(){
	int n, x;
	int y = 200;
	cin>>n;
	x = n*800;
	n/=15;
	y*=n;
	cout<<x-y;
	
	return 0;
	
}